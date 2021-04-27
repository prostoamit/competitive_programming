#include "gcd.h"

int Gcd::gcd(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else b = b % a;
    }
    return a + b;
}

int Gcd::lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

