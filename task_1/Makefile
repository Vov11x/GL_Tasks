ifndef GTEST_DIR
GTEST_DIR = ../googletest/googletest
endif

CC = g++
CPPFLAGS += -isystem $(GTEST_DIR)/include
CCFLAGS += -g -std=gnu++17 -Wall -pthread

TESTS = stack_gTest
MAIN = main
SOURCE_DIR = project
TEST_DIR = test

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)


all : $(MAIN) $(TESTS)

main : stack.o main.o
	$(CC) stack.o main.o -o $(MAIN)

main.o : $(SOURCE_DIR)/main.cpp
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $(SOURCE_DIR)/main.cpp

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

stack.o : $(SOURCE_DIR)/stack.cpp $(SOURCE_DIR)/stack.h
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $(SOURCE_DIR)/stack.cpp

stack_gTest.o : $(TEST_DIR)/stack_gTest.cpp $(SOURCE_DIR)/stack.h $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) -I$(SOURCE_DIR) $(CCFLAGS) -c $(TEST_DIR)/stack_gTest.cpp

stack_gTest : stack.o stack_gTest.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CCFLAGS) -lpthread $^ -o $@ -L. -L$(SOURCE_DIR)