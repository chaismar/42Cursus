#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :  AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = src;    
}

PresidentialPardonForm &PresidentialPardonForm::PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this == &other)
        return *this;
    this->target = other.target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (this->getStatus() == true)
        {
            if (executor.getGrade() <= this->getExecGrade())
                std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
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

std::ostream    &operator<<(std::ostream &o, const PresidentialPardonForm &a)
{
    o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecGrade() <<
	"\n\tis signed:\t" << a.getStatus() <<
	std::endl;
	return (o);
}