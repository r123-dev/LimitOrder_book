CXX=g++
CXXFLAGS=-std=c++17 -Iinclude -Ilib -lcurl
SRC=src/main.cpp src/OrderBook.cpp src/Logger.cpp src/Order.cpp src/Trade.cpp
TESTS=tests/test_orderbook.cpp src/OrderBook.cpp src/Order.cpp src/Trade.cpp

all: lob_engine

lob_engine:
	$(CXX) $(CXXFLAGS) $(SRC) -o lob_engine

test:
	$(CXX) $(CXXFLAGS) $(TESTS) -o run_tests
	./run_tests

clean:
	rm -f lob_engine run_tests
