#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "cppDES/des.h"
#include "crush.hpp"

//using namespace std;
//#include "tests.h"
//#include "fileencryption.h"

// void usage()
// {
//     cout << "Usage: cppDES -e/-d key [input-file] [output-file]" << endl;
// }

// int main(int argc, char **argv)
// {
//     //alltests(); return 0;

//     if(argc < 3)
//     {
//         usage();
//         return 1;
//     }

//     string enc_dec = argv[1];
//     if(enc_dec != "-e" && enc_dec != "-d")
//     {
//         usage();
//         return 2;
//     }

//     string input,output;
//     if(argc > 3)
//         input  = argv[3];
//     if(argc > 4)
//         output = argv[4];

//     ui64 key = strtoull(argv[2], nullptr, 16);
//     FileEncryption fe(key);

//     if(enc_dec == "-e")
//         return fe.encrypt(input, output);
//     std::cout << hex << output
//     if(enc_dec == "-d")
//         return fe.decrypt(input, output);

//     return 0;
// }

int main(){
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
