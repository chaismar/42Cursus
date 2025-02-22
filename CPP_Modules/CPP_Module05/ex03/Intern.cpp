#include "Intern.hpp"
#include <iostream>

const std::string	Intern::names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const CF			Intern::forms[3] = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};

Intern::Intern() {}

Intern::~Intern() {}

void Intern::cleanup(AForm *form)
{
	delete form;
}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern&	Intern::operator=(const Intern& o) {
	if (this != &o) {}
	return *this;
}

AForm*	Intern::ShrubberyCreation(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::RobotomyRequest(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::PresidentialPardon(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string& form,const std::string& target) const {
	AForm *newform;
	for (int i = 0; i < 3; i++)
		if (names[i] == form)
		{
			newform = (this->*(forms[i]))(target);
			return newform;
		}
	throw FormNotFoundException();
}

const char*	Intern::FormNotFoundException::what() const throw() {
	return "<Intern> Form not found! May I bring you a coffee instead?";
}