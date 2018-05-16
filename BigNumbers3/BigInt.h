#pragma once

#include "BitPack.h"
#include <vector>
#include <regex>

class BigInt {
private:
	std::vector<BitPack> _pack;
	size_t _size;
public:
	BigInt(std::string input = "");

	void convert(std::string input);

	BigInt & operator=(const BigInt & rhs);

	BigInt & operator+(const BigInt & rhs);

	BigInt & operator+(const double & rhs);

	template <typename T>
	BigInt & operator+(const T & rhs) {
		try {
			BigInt temp = *this;
			temp += rhs;
		}
		catch (std::string err) {
			std::cerr << err << std::endl;
			exit(13);
		}

		return temp;
	}

	BigInt & operator-(const BigInt & rhs);
};