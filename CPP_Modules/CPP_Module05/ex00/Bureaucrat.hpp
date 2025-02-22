#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
		Bureaucrat &operator=(const Bureaucrat &src);

	private:
		void				setGrade(int);
		const std::string 	_name;
		int 				_grade;


	class GradeTooHighException  : public std::exception
	{
	};

	class GradeTooLowException : public std::exception
	{
	};
};
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif