#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    std::cout << "RobotomyRequestForm default construtor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destrutor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm construtor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :  AForm("RobotomyRequestForm", 72, 45)
{
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &o)
{
    if (this == &o)
        return *this;
    this->target = o.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (this->getStatus() == true)
        {
            if (executor.getGrade() <= this->getExecGrade())
            {
                std::cout << "* Driling Noise *";
                std::cout << this->target << " has been robotomized" << std::endl;
            }
            else
                throw AForm::GradeTooLowException();
        }
        else
            throw std::out_of_range("Form not signed");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}

std::ostream    &operator<<(std::ostream &o, const RobotomyRequestForm &a)
{
    o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecGrade() <<
	"\n\tis signed:\t" << a.getStatus() <<
	std::endl;
	return (o);
}