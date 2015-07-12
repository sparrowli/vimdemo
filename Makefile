TESTS = math_unittest
VIM_DEMO = .
SRC_DIR = $(VIM_DEMO)/src
TEST_DIR = $(VIM_DEMO)/test
LIB_DIR = $(VIM_DEMO)/lib
MEDIAN_DIR = $(VIM_DEMO)/median
EXECUTABLE_APP = $(VIM_DEMO)/bin

all : $(TESTS)

clean :
	rm -rf $(EXECUTABLE_APP)/* $(MEDIAN_DIR)/*.o *.o

build_src : 
	$(CXX) -c $(SRC_DIR)/*.cpp 

build_test :
	$(CXX) -Isrc -I. -c $(TEST_DIR)/*.cpp 

math_unittest : build_src build_test
	$(CXX) -pthread $(VIM_DEMO)/*.o $(LIB_DIR)/*.a -o $(EXECUTABLE_APP)/$@
