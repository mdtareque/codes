#include<stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    unsigned long long c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return a * (b / gcd(a, b));
}
