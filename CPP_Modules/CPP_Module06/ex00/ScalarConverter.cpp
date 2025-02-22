#include "ScalarConverter.hpp"
#include <sstream>
#include <stdlib.h>
#include <string>

static int ft_stoi(const std::string & s ) {
    int i;
    std::istringstream(s) >> i;
    return i;
}

static bool isDecimal(const std::string &str){
	size_t decimal_count = 0;
	for (int i = 0; str[i]; i++)
	{
		if (std::isdigit(str[i]) && str[i] != '.')
			return false;
		if (str[i] == '.')
		{
			decimal_count++;
			if (decimal_count > 1)
				return false;
		}
	}
	return true;	
}

static std::string convertEz(const std::string &literal){    
    std::stringstream ss;
    int i = ft_stoi(literal);
    double d = atof(literal.c_str());

    if ((i >= 0 && i <= 31) || i == 127 || i == 255)
        ss << "char: " << "Non displayable" << std::endl;
    else if (i < 0 || i > 255)
        ss << "char: " << "doesn't exist" << std::endl;
    else
        ss << "char: " << static_cast<char>(i) << std::endl;
    ss << "int: " << i << std::endl;
    if (i == d)
    {
        ss << "float: "  << d << ".0f" << std::endl;
        ss << "double: "  << d << ".0" << std::endl;
    }
    else
    {
        ss << "float: "  << d << "f" << std::endl;
        ss << "double: "  << d << std::endl;
    }
    return ss.str();
}



static std::string handle_specials(const std::string &literal){
    std::stringstream ss;

    if (!literal.compare("nan"))
    {
        ss << "char: " << " impossible" << std::endl << "int: " << "impossible" << std::endl << "float: "  << "nanf" << std::endl << "double: "  << "nan" << std::endl;
        return ss.str();
    }
    if (!literal.compare("-inf"))
    {
        ss << "char: " << " impossible" << std::endl << "int: " << "impossible" << std::endl << "float: "  << "-inff" << std::endl << "double: "  << "-inf" << std::endl;
        return ss.str();
    }
    if (!literal.compare("+inf"))
    {
        ss << "char: " << " impossible" << std::endl << "int: " << "impossible" << std::endl << "float: "  << "+inff" << std::endl << "double: "  << "+inf" << std::endl;
        return ss.str();
    }
    if (!literal.compare("-inff"))
    {
        ss << "char: " << " impossible" << std::endl << "int: " << "impossible" << std::endl << "float: "  << "-inff" << std::endl << "double: "  << "-inf" << std::endl;
        return ss.str();
    }
    if (!literal.compare("+inff"))
    {
        ss << "char: " << " impossible" << std::endl << "int: " << "impossible" << std::endl << "float: "  << "+inff" << std::endl << "double: "  << "+inf" << std::endl;
        return ss.str();
    }
    return ("case not handled\n");
}

std::string ScalarConverter::convert(const std::string &literal) {
	if (!isDecimal(literal))
        return convertEz(literal);
    if (literal.size() < 1)
        return "Nothing input nothing to print\n";
    if (literal.size() == 1)
    {
        int a = static_cast<char>(literal[0]);
        std::stringstream ss;
        ss << a;
        return convertEz(ss.str());
    }
    return handle_specials(literal);
}

ScalarConverter::ScalarConverter()
{}
ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    if (this != &cpy)
        std::cout << "copy constructor called";
}

ScalarConverter & ScalarConverter:: operator=(const ScalarConverter &cpy)
{
    if (this != &cpy)
        return *this;
    return *this;
}