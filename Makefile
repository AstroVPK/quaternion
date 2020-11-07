test: include/quaternion.hpp src/test.cpp
	g++ -std=c++17 -Iinclude/ src/test.cpp -o bin/test

run: bin/test
	./bin/test

.PHONY : all

all : test run

.PHONY: clean

clean:
	rm bin/test
