#include <iostream>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string *p = &s;
    std::string& ref = s;

    std::cout << s << "\n";
    std::cout << *p << "\n";
    std::cout << ref << "\n\n";

    std::cout << &s << "\n";
    std::cout << p << "\n";
    std::cout << &ref << "\n";
}