#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    // Create Bureaucrats
    Bureaucrat john("John", 2);
    Bureaucrat jane("Jane", 149);

    // Output Bureaucrats
    std::cout << "=== Bureaucrats ===" << std::endl;
    std::cout << john << std::endl;
    std::cout << jane << std::endl;
    std::cout << std::endl;

    // Create Forms
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    // Output Forms
    std::cout << "=== Forms ===" << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;
    std::cout << std::endl;

    // Try signing forms with Bureaucrats
    std::cout << "=== Signing Forms ===" << std::endl;
    john.signForm(shrubbery);  // Should succeed
    john.signForm(shrubbery);  // Should fail
    jane.signForm(robotomy);   // Should fail
    john.signForm(robotomy);   // Should succeed
    john.signForm(pardon);     // Should succeed
    std::cout << std::endl;

    // Output Forms after signing attempts
    std::cout << "=== Forms After Signing Attempts ===" << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;
    std::cout << std::endl;

    // Try executing forms with Bureaucrats
    std::cout << "=== Executing Forms ===" << std::endl;
    john.executeForm(shrubbery);  // Should succeed
    jane.executeForm(robotomy);   // Should fail
    john.executeForm(robotomy);   // Should succeed (50% chance)
    john.executeForm(pardon);     // Should succeed
    std::cout << std::endl;

    std::cout << "=== end ===" << std::endl;
    return 0;
}
