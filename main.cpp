#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "cppDES/des.h"
#include "crush.hpp"

const unsigned long ONE = 1;

static unsigned long x=123456789, y=362436069, z=521288629;

unsigned long fast_random(void) {
    unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;

    return z;
}

unsigned long get_nth_bit(unsigned long x, int n) {
    return (x & (1 << n)) >> n;
}

unsigned long effective_bits_equation4_13bits(unsigned long p, unsigned long c) {
    unsigned long result = 0;
    result = (get_nth_bit(p, 11) &
              (get_nth_bit(p, 12) >> 1) &
              (get_nth_bit(p, 13) >> 2) &
              (get_nth_bit(p, 14) >> 3) &
              (get_nth_bit(p, 15) >> 4) &
              (get_nth_bit(p, 16) >> 5) &
              (get_nth_bit(c, 0) >> 6) &
              (get_nth_bit(c, 27) >> 7) &
              (get_nth_bit(c, 28) >> 8) &
              (get_nth_bit(c, 29) >> 9) &
              (get_nth_bit(c, 30) >> 10) &
              (get_nth_bit(c, 31) >> 11) &
              ((get_nth_bit(p, 39) ^ 
                get_nth_bit(p, 50) ^
                get_nth_bit(p, 56) ^
                get_nth_bit(c, 47) ^
                get_nth_bit(c, 7) ^
                get_nth_bit(c, 18) ^
                get_nth_bit(c, 24) ^
                get_nth_bit(c, 28)) >> 12))

    return result;
}

unsigned long effective_bits_equation4_12bits(unsigned long k1, unsigned long k16) {
    unsigned long result = 0;
    result = (get_nth_bit(k1, 18) &
              (get_nth_bit(k1, 19) >> 1) &
              (get_nth_bit(k1, 20) >> 2) &
              (get_nth_bit(k1, 21) >> 3) &
              (get_nth_bit(k1, 22) >> 4) &
              (get_nth_bit(k1, 23) >> 5) &
              (get_nth_bit(k16, 42) >> 6) &
              (get_nth_bit(k16, 43) >> 7) &
              (get_nth_bit(k16, 44) >> 8) &
              (get_nth_bit(k16, 45) >> 9) &
              (get_nth_bit(k16, 46) >> 10) &
              (get_nth_bit(k16, 47) >> 11)) 

    return result;
}

unsigned long effective_bits_equation5_13bits(unsigned long p, unsigned long c) {
    return effective_bits_equation4_13bits(c, p);
}

unsigned long effective_bits_equation5_12bits(unsigned long k1, unsigned long k16) {
    return effective_bits_equation4_12bits(k16, k1);
}

unsigned long left_side_of_equation4(unsigned long f1, unsigned long f16, unsigned long t, unsigned long k) {
    unsigned long result = 0;

    unsigned long result = 0;
    result = (get_nth_bit(t, 12) ^
              get_nth_bit(f1, 7) ^ get_nth_bit(f1, 18) ^ get_nth_bit(f1, 24) ^
              get_nth_bit(f16, 15))

    return result;
}

unsigned long left_side_of_equation5(unsigned long f1, unsigned long f16, unsigned long t, unsigned long k) {
    return left_side_of_equation4(f1, f16, k, t);
}

int main(){
	int TA[8192], TB[8192];
    int KA[4096], KB[4096];
	long count = 0;

    std::cout << (1 << 2);

	for (long i = 0; i < (ONE << 43); ++i) {
        unsigned long p = fast_random();
        unsigned long c = DES::encrypt(p);

        TA[effective_bits_equation4_13bits(p, c)]++;
        TB[effective_bits_equation5_13bits(p, c)]++;
	}

    for (long k = 0; k < (ONE << 12); ++k) {
        for (long t = 0; t < (ONE << 13); ++t) {
            if (left_side_of_equation4(DES::f(p, 1), DES::f(p, 16), t, k) == 0) {
                KA[k] += TA[t];
            }

            if (left_side_of_equation5(DES::f(p, 1), DES::f(p, 16), t, k) == 0) {
                KB[k] += TB[t];
            }
        }
    }

	std::cout << N/2/2 << std::endl;
	uint64_t key = 0x0000;
	uint64_t msg = 0x0000;
	
	std::cout << "key=" << key << std::endl;
	std::cout << "msg=" << msg << std::endl;
	uint64_t cipher = DES::decrypt(msg, key);
	//std::cout << hex << cipher << std::endl;

	std::vector<T> r0{N/2 + 1488, N/2 + 55, N/2 - 77, N/2, N/2 + 1, N/2 - 90, N/2 + 7, N/2 - 3};
	std::vector<T> r1{N/2 + 1488, N/2 + 55, N/2 - 77, N/2, N/2 + 1, N/2 - 90, N/2 + 7, N/2 - 3};
	print(r1);  
	std::cout << std::endl;
	rearrange(r0.data(), r1.data());
	print(r1);

        crush(r0.data(), r1.data());
}
