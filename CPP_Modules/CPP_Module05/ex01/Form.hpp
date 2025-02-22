#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    public :
        Form ();
        ~Form ();
        Form (const Form &src);
        Form (int, int);
        Form (const std::string);
        Form (const std::string, int, int);

        const std::string   getName();
        int                 getSignGrade();
        int                 getExecGrade();
        bool                getStatus();
        void                beSigned(Bureaucrat &signer);
    class GradeTooHighException : public std::exception{
        public:
		    virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
		    virtual const char *what() const throw();
    };
    class FormAlreadySignedException : public std::exception{
        public:
		    virtual const char *what() const throw();
    };
    private :
        const std::string   _name;
        bool                _signed;
        int                 _sign_grade;
        int                 _exec_grade;
};  

std::ostream    &operator<<(std::ostream &o, Form *a);

#endif