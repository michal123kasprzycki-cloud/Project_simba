#pragma once
#include <iostream>
#include <vector>
using namespace std;

class IPv4PrefixSet {
private:
    struct Prefix {
        uint32_t ip;
        uint8_t mask;
    };

public:

    bool add(const uint32_t& base, const uint8_t maskLength);

    bool del(const uint32_t& base, const uint8_t maskLength);

    int check(const uint32_t& ip);

};
