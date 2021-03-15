#include <iostream>
#include <cstring>
#include "fibSum.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Error! 2 arguments are necessary. \n(Please, use flag `help` to get more info.)\n";
        exit(1);
    }

    if (std::strcmp(argv[1],"help") == 0) {
        std::cout << "Help:\n\n";
        std::cout << "\t- Use positive integer as an argument to compute the sum of N first numbers Fibonacci.\n";
    } else {
        try {
            int N = atoi(argv[1]);
            std::cout << "The sum of " << N << " first numbers Fibonacci is equal to: " << fibSum(N) << ".\n";
        } catch (const std::exception& ex) {
            std::cout << ex.what() << '\n';
            std::cout << "Incorrect argument, try again.\n";
        }
    }

    return 0;
}
