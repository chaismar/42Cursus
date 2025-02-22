#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
    public :
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm(std::string target);
        
        void execute(Bureaucrat const &executor) const;
        
        PresidentialPardonForm &operator=(const PresidentialPardonForm &o);
    private :
        std::string target;
};

std::ostream    &operator<<(std::ostream &o, const PresidentialPardonForm &a);

#endif