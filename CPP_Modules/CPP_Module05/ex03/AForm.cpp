#include "AForm.hpp"

AForm::AForm() : _name("Form"), _signed(false), _sign_grade(1), _exec_grade(1)
{
    std::cout << "Form default constructor called \n";
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form destructor called" << std::endl; 
}

AForm::AForm(const AForm &src) : _name(src._name + "_copy"), _signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
    std::cout << "Form constructor called \n";
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

AForm::AForm(int sign_grade, int exec_grade) : _name("Form"), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "Form constructor called \n";
	if (sign_grade > 150 || exec_grade > 150)
		throw(AForm::GradeTooLowException());
	else if( sign_grade < 1 || exec_grade < 1)
		throw(AForm::GradeTooHighException());
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

AForm::AForm(const std::string name) : _name(name), _signed(false), _sign_grade(1), _exec_grade(1)
{
    std::cout << "Form constructor called \n";
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "Form constructor called \n";
	if (sign_grade > 150 || exec_grade > 150)
		throw(AForm::GradeTooLowException());
	else if( sign_grade < 1 || exec_grade < 1)
		throw(AForm::GradeTooHighException());
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

const std::string AForm::getName() const
{
    return this->_name;
}

int AForm::getSignGrade() const
{
    return this->_sign_grade;
}

int AForm::getExecGrade() const
{
    return this->_exec_grade;
}

bool AForm::getStatus() const
{
    return this->_signed;
}

void AForm::beSigned(Bureaucrat &signer)
{
    if(signer.getGrade() >  this->getSignGrade())
        throw (Bureaucrat::GradeTooLowException());
    else if (this->_signed != true)
    {
        this->_signed = true;
        std::cout << "Form is now signed by " << signer.getName() << " with a grade of " << signer.getGrade() << std::endl;
    }
    else
        std::cout << "Form already signed" << std::endl;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, const AForm &a)
{
	o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecGrade() <<
	"\n\tis signed:\t" << a.getStatus() <<
	std::endl;
	return (o);
}