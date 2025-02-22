#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create Bureaucrats
        Bureaucrat john("John", 2);
        Bureaucrat jane("Jane", 149);

        // Output Bureaucrats
        std::cout << "=== Bureaucrats ===" << std::endl;
        std::cout << john << std::endl;
        std::cout << jane << std::endl;
        std::cout << std::endl;

        // Create Intern
        Intern someRandomIntern;

        // Make Forms using raw pointers
        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        // Output Forms
        std::cout << "=== Forms ===" << std::endl;
        if (shrubbery) std::cout << *shrubbery << std::endl;
        if (robotomy) std::cout << *robotomy << std::endl;
        if (pardon) std::cout << *pardon << std::endl;
        std::cout << std::endl;

        // Try signing forms with Bureaucrats
        std::cout << "=== Signing Forms ===" << std::endl;
        if (shrubbery) john.signForm(*shrubbery);  // Should succeed
        if (robotomy) jane.signForm(*robotomy);    // Should fail
        if (robotomy) john.signForm(*robotomy);    // Should succeed
        if (pardon) john.signForm(*pardon);        // Should succeed
        std::cout << std::endl;

        // Output Forms after signing attempts
        std::cout << "=== Forms After Signing Attempts ===" << std::endl;
        if (shrubbery) std::cout << *shrubbery << std::endl;
        if (robotomy) std::cout << *robotomy << std::endl;
        if (pardon) std::cout << *pardon << std::endl;
        std::cout << std::endl;

        // Try executing forms with Bureaucrats
        std::cout << "=== Executing Forms ===" << std::endl;
        if (shrubbery) john.executeForm(*shrubbery);  // Should succeed
        if (robotomy) jane.executeForm(*robotomy);    // Should fail
        if (robotomy) john.executeForm(*robotomy);    // Should succeed (50% chance)
        if (pardon) john.executeForm(*pardon);        // Should succeed
        std::cout << std::endl;

        // Clean up
        someRandomIntern.cleanup(shrubbery);
        someRandomIntern.cleanup(robotomy);
        someRandomIntern.cleanup(pardon);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
