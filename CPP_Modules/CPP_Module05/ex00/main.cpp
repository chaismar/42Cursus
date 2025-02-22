#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // Create Bureaucrats with valid grades
    Bureaucrat john("John", 2);
    std::cout << john << std::endl;

    john.promote();
    std::cout << john << std::endl;

    // The following increment should throw an exception as the grade will be 0
    john.promote();
    std::cout << john << "\n" << std::endl;

    // Create another Bureaucrat with a valid grade
    Bureaucrat jane("Jane", 149);
    std::cout << jane << std::endl;

    jane.demote();
    std::cout << jane << std::endl;

    // The following decrement should throw an exception as the grade will be 151
    jane.demote();
    std::cout << jane << "\n" <<std::endl;

    // Create Bureaucrats with invalid grades to trigger exceptions in the constructor
    Bureaucrat invalidHigh("InvalidHigh", 0);
    std::cout << std::endl;
    Bureaucrat invalidLow("InvalidLow", 151);
    std::cout << std::endl;

    return 0;
}