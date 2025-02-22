#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern;

typedef AForm* (Intern::*CF)(const std::string&) const;

class Intern
{
    public :
        Intern();
        ~Intern();
        Intern(const Intern &o);
        void cleanup(AForm *form);
        Intern& operator=(const Intern &o);

        AForm *makeForm(const std::string& form, const std::string& target) const;

        class FormNotFoundException: public std::exception{
            virtual const char* what() const throw();
        };

    private :
        static const std::string    names[3];
        static const CF             forms[3];
        AForm*	ShrubberyCreation(const std::string& target) const;
	    AForm*	RobotomyRequest(const std::string& target) const;
	    AForm*	PresidentialPardon(const std::string& target) const;
};
#endif