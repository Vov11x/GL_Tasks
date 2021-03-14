ifndef GTEST_DIR
GTEST_DIR = ../googletest/googletest
endif

CC = g++
CPPFLAGS += -isystem $(GTEST_DIR)/include
CCFLAGS += -g -std=gnu++17 -Wall -Wextra -pthread

TESTS = fibSum_gTest
SOURCE_DIR = project
TEST_DIR = test

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)


all : $(TESTS)

clean :
	rm -fr $(TESTS) *.a *.o


gtest-all.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CCFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CCFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

fibSum.o : $(SOURCE_DIR)/fibSum.cpp $(SOURCE_DIR)/fibSum.h
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $(SOURCE_DIR)/fibSum.cpp

fibSum_gTest.o : $(TEST_DIR)/fibSum_gTest.cpp $(SOURCE_DIR)/fibSum.h $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) -I$(SOURCE_DIR) $(CCFLAGS) -c $(TEST_DIR)/fibSum_gTest.cpp

fibSum_gTest : fibSum.o fibSum_gTest.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CCFLAGS) -lpthread $^ -o $@ -L. -L$(SOURCE_DIR)