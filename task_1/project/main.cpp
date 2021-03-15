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

    if (argc < 2) {
        std::cout << "Too few arguments, at least 2 are necessary.\n";
        std::cout << "Use argument `help` to see more info.\n";
        exit(1);
    }

    if (std::strcmp(argv[1],"help") == 0) {

        std::cout << "Help:\n\n";
        std::cout << "\t- Provide as arguments type of data (int, char, double or string) and elements to create a stack.\n";
        std::cout << "\nExample:\n";
        std::cout << "./main int 5 6 7 8 9 10\n";
        std::cout << "Small stack with 6 integer elements.\n";
        exit(0);
    }

    if (argc > 2) {
        if (!std::strcmp(argv[1],"int")) {
            stack<int> st(argc - 2);
            while (argc-- > 2) {
                st.push(atoi(argv[argc]));
            }
            std::cout << "Data type: int\n";
            print_stack(st);
        } else if (!std::strcmp(argv[1],"char")) {
            stack<char> st(argc - 2);
            while (argc-- > 2) {
                st.push(argv[argc][0]);
            }
            std::cout << "Data type: char\n";
            print_stack(st);
        } else if (!std::strcmp(argv[1],"double")) {
            stack<double> st(argc - 2);
            while (argc-- > 2) {
                st.push(atof(argv[argc]));
            }
            std::cout << "Data type: double\n";
            print_stack(st);
        }
        else if (!std::strcmp(argv[1],"string")) {
            stack<std::string> st(argc - 2);
            while (argc-- > 2) {
                st.push(std::string(argv[argc]));
            }
            std::cout << "Data type: string\n";
            print_stack(st);
        }
        else {
            std::cout << "Unknown data type. Please, use `help` argument.\n";
        }
    }

    return 0;
}
