TESTS = math_unittest
VIM_DEMO = .
SRC_DIR = $(VIM_DEMO)/src
TEST_DIR = $(VIM_DEMO)/test
LIB_DIR = $(VIM_DEMO)/lib
MEDIAN_DIR = $(VIM_DEMO)/median
EXECUTABLE_APP = $(VIM_DEMO)/bin

all : $(TESTS)

clean :
	rm -rf $(EXECUTABLE_APP)/* $(MEDIAN_DIR)/*.o

math_utilities.o : 
	$(CXX) -c $(SRC_DIR)/*.cpp -o $(MEDIAN_DIR)/$@

math_utilities_test.o :
	$(CXX) -Isrc -I. -c $(TEST_DIR)/*.cpp -o $(MEDIAN_DIR)/$@

math_unittest : math_utilities.o math_utilities_test.o 
	$(CXX) -pthread $(MEDIAN_DIR)/*.o $(LIB_DIR)/*.a -o $(EXECUTABLE_APP)/$@
