#include <iostream>
#include <cstring>
#include "stack.cpp"


template <typename T>
void print_stack(stack<T> st) {
    std::cout << "Elements: ";
    while (st.capacity()) {
        std::cout << st.pop() << ' ';
    }
    std::cout << '\n';
}


int main(int argc, char *argv[]) {
    // in case of one argument
    if (argc < 2) {
        std::cout << "Too few arguments, at least 2 are necessary.\n";
        std::cout << "Use argument `help` to see more info.\n";
        exit(1);
    }

    // help info
    if (std::strcmp(argv[1],"help") == 0) {

        std::cout << "Help:\n\n";
        std::cout << "\t- Provide as arguments type of data (int or string) and elements to create a stack.\n";
        std::cout << "\nExample:\n";
        std::cout << "./main int 5 6 7 8 9 10\n";
        std::cout << "Small stack with 6 integer elements.\n";
        exit(0);
    }

    // demo version of interface
    if (argc > 2) {
        if (!std::strcmp(argv[1],"int")) {
            stack<int> st(argc - 2);
            while (argc-- > 2) {
                st.push(atoi(argv[argc]));
            }
            std::cout << "Type of data: int\n";
            print_stack(st);
        } else if (!std::strcmp(argv[1],"string")) {
            stack<std::string> st(argc - 2);
            while (argc-- > 2) {
                st.push(std::string(argv[argc]));
            }
            std::cout << "Type of data: string\n";
            print_stack(st);
        }
        else {
            std::cout << "Unknown data type.\n"
                         "Please, use `help` as an argument to get more info.\n";
        }
    }

    return 0;
}
