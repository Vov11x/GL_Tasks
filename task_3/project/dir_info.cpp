#include "dir_info.h"


std::size_t count_files_in_dir(const fs::path& path) {
    return (std::size_t)std::distance(fs::directory_iterator{path}, fs::directory_iterator{});
}

void print_files_in_dir(const fs::path& path) {
    for (const auto & entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
    }
}