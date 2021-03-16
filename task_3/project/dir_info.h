#include <iostream>
#include <thread>
#include <filesystem>

namespace fs = std::filesystem;

std::size_t count_files_in_dir(const fs::path& path);
void print_files_in_dir(const fs::path& path);
