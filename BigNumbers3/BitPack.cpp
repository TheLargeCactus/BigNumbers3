#include "BitPack.h"

BitPack::BitPack(size_t size, uint64_t bits)
{
	setSize(size);
	setBits(bits);
}

size_t BitPack::setSize(size_t size)
{
	try {
		if (size < 0) {
			throw error("Size of BitPack cannot be less than 0");
		}

		if (size > _max) {
			throw error("Size of BitPack cannot be greater than " + std::to_string(_max));
		}
	}
	catch (const char * err) {
		std::cerr << err << std::endl;
		exit(13);
	}
	
	size_t temp = _size;

	_size = size;

	return temp;
}

size_t BitPack::getSize()
{
	return _size;
}

bool BitPack::setBit(size_t index, bool val)
{
	try {
		if (index < 0) {
			throw error("index of input to setBit cannot be less than 0");
		}

		if (index > _max) {
			throw error("index of input to setBit cannot be greater than " + std::to_string(_max));
		}
	}
	catch (const char * err) {
		std::cerr << err << std::endl;
		exit(13);
	}

	if (val) {
		_bits |= 1 << index;
	}
	else {
		_bits &= ~(1 << index);
	}

	return val;
}

uint64_t BitPack::setBits(uint64_t val)
{
	_bits = val;

	return val;
}

bool BitPack::getBit(size_t index)
{
	try {
		if (index < 0) {
			throw error("index of input to getBit cannot be less than 0");
		}

		if (index > _max) {
			throw error("index of input to getBit cannot be greater than " + std::to_string(_max));
		}
	}
	catch (const char * err) {
		std::cerr << err << std::endl;
		exit(13);
	}

	return _bits & (1 << index);
}

std::string error(std::string msg)
{
	return "Error: " + (std::string)__FILE__ + ": " + msg;
}
