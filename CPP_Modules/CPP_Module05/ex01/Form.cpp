#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _sign_grade(1), _exec_grade(1)
{
    std::cout << "Form default constructor called \n";
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;   
}

Form::Form(const Form &src) : _name(src._name + "_copy"), _signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
    std::cout << "Form constructor called \n";
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

Form::Form(int sign_grade, int exec_grade) : _name("Form"), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "Form constructor called \n";
	if (sign_grade > 150 || exec_grade > 150)
		throw(Form::GradeTooLowException());
	else if( sign_grade < 1 || exec_grade < 1)
		throw(Form::GradeTooHighException());
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

Form::Form(const std::string name) : _name(name), _signed(false), _sign_grade(1), _exec_grade(1)
{
    std::cout << "Form constructor called \n";
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "Form constructor called \n";
	if (sign_grade > 150 || exec_grade > 150)
		throw(Form::GradeTooLowException());
	else if( sign_grade < 1 || exec_grade < 1)
		throw(Form::GradeTooHighException());
    std::cout << "Form name is " << this->getName() << " grade to sign is " << this->getSignGrade() << " grade to exec is " << this->getExecGrade() << std::endl;
}

const std::string Form::getName()
{
    return this->_name;
}

int Form::getSignGrade()
{
    return this->_sign_grade;
}

int Form::getExecGrade()
{
    return this->_exec_grade;
}

bool Form::getStatus()
{
    return this->_signed;
}

void Form::beSigned(Bureaucrat &signer)
{
    if(signer.getGrade() > this->getSignGrade())
        throw (Bureaucrat::GradeTooLowException());
    else if (this->_signed != true)
    {
        this->_signed = true;
        std::cout << "- Form : " << this->getName() << " is now signed by " << signer.getName() << " with a grade of " << signer.getGrade() << std::endl;
    }
    else
        throw (Form::FormAlreadySignedException());
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};
const char *Form::FormAlreadySignedException::what(void) const throw()
{
    return ("already signed");
};

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getStatus() <<
	std::endl;
	return (o);
}