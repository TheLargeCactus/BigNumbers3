#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>


//Error-display function
std::string error(std::string msg);


//Class contains a number of bits packed into single memory space
class BitPack {
private:
	const int _max = 64;
	uint64_t _bits;
	size_t _size;

public:
	//Call Constructor, default arguments initialize size of 64 with all values of 0
	BitPack(size_t size = 0, uint64_t bits = 0);

	//set size of BitPack to value given by parameter, return old value
	size_t setSize(size_t size);

	//return current _size of object
	size_t getSize();

	//set bit at location given by index to value, return val
	bool setBit(size_t index, bool val);

	uint64_t setBits(uint64_t val);

	//return current value of bit at location given by index
	bool getBit(size_t index);

	
};