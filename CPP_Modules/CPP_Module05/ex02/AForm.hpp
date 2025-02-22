#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
    public :
        AForm ();
        ~AForm();
        AForm (const AForm &src);
        AForm (int, int);
        AForm (const std::string);
        AForm (const std::string, int, int);

        const std::string   getName() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        bool                getStatus() const;
        void                beSigned(Bureaucrat &signer);

        virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception{
        public:
		    virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
		    virtual const char *what() const throw();
    };
    private :
        const std::string   _name;
        bool                _signed;
        int                 _sign_grade;
        int                 _exec_grade;
};  

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif