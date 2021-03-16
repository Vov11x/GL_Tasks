#include "dir_info.h"
#include "gtest/gtest.h"


TEST(dir_info, incorrect_path_in_printing_function) {
    EXPECT_THROW(print_files_in_dir("./abcdef/"), fs::filesystem_error);
}

TEST(dir_info, incorrect_path_in_counting_function) {
    EXPECT_THROW(count_files_in_dir("./abcdef/"), fs::filesystem_error);
}

TEST(dir_info, correct_path_in_printing_function) {
    EXPECT_NO_THROW(print_files_in_dir("./"));
}

TEST(dir_info, correct_path_in_counting_function) {
    EXPECT_NO_THROW(count_files_in_dir("./"));

}



int main(int argc, char** argv)
{
    printf("Running main() from fibSum_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}


