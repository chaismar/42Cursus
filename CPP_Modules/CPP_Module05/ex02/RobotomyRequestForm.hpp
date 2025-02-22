#ifndef RobotomyRequestForm_CPP
#define RobotomyRequestForm_CPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
    public :
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm(std::string target);
        void execute(Bureaucrat const &executor) const;
        
        RobotomyRequestForm &operator=(const RobotomyRequestForm &o);
    private :
        std::string target;
};

std::ostream    &operator<<(std::ostream &o, const RobotomyRequestForm &a);

#endif