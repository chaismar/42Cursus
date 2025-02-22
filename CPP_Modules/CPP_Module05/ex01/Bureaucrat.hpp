#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int i);
		const std::string	getName();
		int 				getGrade();
		void				promote();
		void				demote();
		void                signForm(Form &form);

		Bureaucrat &operator=(const Bureaucrat &src);
	class GradeTooHighException  : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	private:
		void				setGrade(int);
		const std::string 	_name;
		int 				_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif