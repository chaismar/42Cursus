#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    // Create Bureaucrats
    Bureaucrat john("John", 1);
    Bureaucrat jane("Jane", 149);

    // Output Bureaucrats
    std::cout << &john << std::endl;
    std::cout << &jane << std::endl;

    // Create Forms
    Form formA("FormA", 1, 1);
    Form formB("FormB", 150, 150);
    Form formC("FormC", 150, 150);

    // Output Forms
    std::cout << &formA << std::endl;
    std::cout << &formB << std::endl;

    // Try signing forms with Bureaucrats
    john.signForm(formA);  // Should succeed
    john.signForm(formB);  // Should succeed
    jane.signForm(formC);  // Should suceed
    jane.signForm(formA);  // Should fail
    jane.signForm(formB);  // Should fail

    // Output Forms after signing attempts
    std::cout << &formA << std::endl;
    std::cout << &formB << std::endl;

    // Test exceptions for invalid Form creation
    try {
        Form invalidHigh("InvalidHigh", 0, 10);  // Should throw GradeTooHighException
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form invalidLow("InvalidLow", 151, 10);  // Should throw GradeTooLowException
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
