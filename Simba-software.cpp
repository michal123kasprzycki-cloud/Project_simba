#include <iostream>
#include <vector>
using namespace std;


class IPv4PrefixSet {
private:
    struct Prefix {
        uint32_t ip;
        uint8_t mask;
    };

    vector <Prefix> z;

public:

    bool add(const uint32_t& base, const uint8_t maskLength) {
        if (maskLength > 32) { return false; }
        for (auto x : z) {
            if (base == x.ip && maskLength == x.mask) {
                return false;
            }
        }
        z.push_back({ base,maskLength });
        return true;
    }

    bool del(const uint32_t& base, const uint8_t maskLength) {
        if (maskLength > 32) { return false; }
        for (int i = 0; i < z.size(); i++) {
            if (z[i].ip == base && z[i].mask == maskLength) {
                swap(z[i].ip, z.back().ip);
                swap(z[i].mask, z.back().mask);
                z.pop_back();
                return true;
            }
        }
        return false;
    }

    int check(const uint32_t& ip) {
        int result = -1;
        for (int i = 0; i < z.size(); i++) {
            uint32_t mask = (z[i].mask == 0 ? 0 : ~0U << (32 - z[i].mask));
            if ((ip & mask) == (z[i].ip & mask)) {
                result = (z[i].mask > result ? z[i].mask : result);
            }
        }
        return result;
    }

};




int main()
{

    return 0;
}









// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
