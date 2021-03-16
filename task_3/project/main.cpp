#include <iostream>
#include <cstring>
#include "dir_info.h"


int main([[maybe_unused]] int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error! Too few arguments (at least must be 2 args).\n";
        std::cout << "Please, use `help` as an argument to get more info.\n";
        exit(1);
    }

    if (!strcmp(argv[1], "help")) {
        std::cout << "Help:\n\n"
                  << "\t- Use file path as an argument.\n"
                  << "\nExample:\n"
                  << "./main ../\n";
        exit(0);
    } else {
        fs::path path = std::string{argv[1]};
        std::size_t number_of_files_in_dir;

        std::thread thr_count([&]() {
            number_of_files_in_dir = count_files_in_dir(path);
        });
        std::thread thr_print(print_files_in_dir, std::ref(path));


        thr_print.join();
        thr_count.join();
        std::cout << "Number of files in " << path
                  << " directory: " << number_of_files_in_dir << '\n';
    }




    return 0;
}
