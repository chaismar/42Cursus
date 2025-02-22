#include "ScalarConverter.hpp"

int main() {
    std::string literal = "nan";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "-inf";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "-inff";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "+inf";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "+inff";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "A";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "42";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "42.0f";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "42.42";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "42.42f";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "0";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "2147483650";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "-2147483650";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    literal = "255";
    std::cout << "input : " << literal << std::endl;
    std::cout << ScalarConverter::convert(literal) << std::endl;
    return 0;
}