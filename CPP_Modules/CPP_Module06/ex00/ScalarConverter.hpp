#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter {
	public:
		static std::string convert(const std::string &literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter &cpy);

};

#endif