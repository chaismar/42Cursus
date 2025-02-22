#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("random"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called "; 
	std::cout << "name is " << this->getName() << " grade is " << this->getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name + "_copy"), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called ";
	std::cout << "name is " << this->getName() << " grade is " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int i) : _name(name)
{
	std::cout << "Bureaucrat constructor called "; 
	try{
		this->setGrade(i);
	}
	catch (const GradeTooHighException & e){
		std::cerr << "\n" << this->getName() << " failed: " << "grade is under 1 " << std::endl <<
		"Grade now set to 150" << std::endl;
		this->setGrade(150);
	}
	catch (const GradeTooLowException& e){
		std::cerr << "\n" << this->getName() << " failed: " << "grade is over 150 " << std::endl <<
		"Grade now set to 150" << std::endl;
		this->setGrade(150);
	}
	std::cout << "name is " << this->getName() << " grade is " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int i) : _name("random")
{
	std::cout << "Bureaucrat constructor called "; 
	try{
		this->setGrade(i);
	}
	catch (const GradeTooHighException & e){
		std::cerr << this->getName() << " failed: " << "grade is under 1 " << std::endl <<
		"Grade now set to 150" << std::endl;
		this->setGrade(150);
	}
	catch (const GradeTooLowException& e){
		std::cerr << this->getName() << " failed: " << "grade is over 150 " << std::endl <<
		"Grade now set to 150" << std::endl;
		this->setGrade(150);
	}
	std::cout << "name is " << this->getName() << " grade is " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat constructor called "; 
	std::cout << "name is " << this->getName() << " grade is " << this->getGrade() << std::endl;
}

void	Bureaucrat::setGrade(int i)
{
	if (i > 150)
		throw GradeTooLowException();
	else if (i < 1)
		throw GradeTooHighException ();
	else
		this->_grade = i;
}

void Bureaucrat::demote()
{
	try
	{
		std::cout << "demoting "<< this->getName() << " from " << this->_grade << " to " << this->_grade + 1 << std::endl; 
		this->setGrade(this->_grade + 1);
	}
	catch (const GradeTooLowException& e){
		std::cerr << this->getName() << " failed: " << "grade is over 150 " << std::endl <<
		"Grade now set to 150" << std::endl;
		this->setGrade(150);
	}
}

void Bureaucrat::promote()
{
	try
	{
		std::cout << "promoting "<< this->getName() << " from " << this->_grade << " to " << this->_grade - 1 << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch (const GradeTooHighException & e){
		std::cerr << this->getName() << " failed: " << "grade is under 1 " << std::endl <<
		"Grade now set to 1" << std::endl;
		this->setGrade(1);
	}
}

const std::string Bureaucrat::getName(void)
{
	return (this->_name);
}

int Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}