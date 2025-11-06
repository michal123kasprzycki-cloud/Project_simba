#include <iostream>
#include <vector>
using namespace std;


class IPv4PrefixSet {
private:
    struct Prefix {
        uint32_t ip;
        uint8_t mask;
    };

    vector <Prefix> IP_vector;

public:

    bool add(const uint32_t& base, const uint8_t maskLength) {
        if (maskLength > 32) { return false; }
        for (auto x : IP_vector) {
            if (base == x.ip && maskLength == x.mask) {
                return false;
            }
        }
        IP_vector.push_back({ base,maskLength });
        return true;
    }

    bool del(const uint32_t& base, const uint8_t maskLength) {
        if (maskLength > 32) { return false; }
        for (int i = 0; i < IP_vector.size(); i++) {
            if (IP_vector[i].ip == base && IP_vector[i].mask == maskLength) {
                swap(IP_vector[i].ip, IP_vector.back().ip);
                swap(IP_vector[i].mask, IP_vector.back().mask);
                IP_vector.pop_back();
                return true;
            }
        }
        return false;
    }

    int check(const uint32_t& ip) {
        int result = -1;
        for (int i = 0; i < IP_vector.size(); i++) {
            uint32_t mask = (IP_vector[i].mask == 0 ? 0 : ~0U << (32 - IP_vector[i].mask));
            if ((ip & mask) == (IP_vector[i].ip & mask)) {
                result = (IP_vector[i].mask > result ? IP_vector[i].mask : result);
            }
        }
        return result;
    }

};

int main()
{
    return 0;
}
