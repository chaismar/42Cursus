#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm(std::string target);
        void execute(Bureaucrat const &executor) const;
        
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &o);
    private :
        std::string target;
};

std::ostream    &operator<<(std::ostream &o, const ShrubberyCreationForm &a);

#endif