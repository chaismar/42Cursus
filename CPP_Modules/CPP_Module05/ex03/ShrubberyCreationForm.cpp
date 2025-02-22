#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl; 
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm deconstructor called" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = src; 
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl; 
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o)
{
    if (this == &o)
        return *this;
    this->target = o.target;
    return *this;
}

static void WriteAsciiTree(const ShrubberyCreationForm *t)
{
    std::ofstream outFile;
    std::string str = t->getName();
    str.append("_shrubbery");
    try
    {
        outFile.open(str.data());
        if (!outFile.is_open())
            throw std::out_of_range("File is not open");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
    outFile <<
"                       ___             \n"
"                 _,-'\"\"   \"\"\"\"`--.     \n"
"              ,-'          __,,-- \\    \n"
"            ,'    __,--\"\"\"\"dF      )   \n"
"           /   .-\"Hb_,--\"\"dF      /    \n"
"         ,'       _Hb ___dF\"-._,-'    \n"
"       ,'      _,-""""   ""--..__      \n"
"      (     ,-'                  `.    \n"
"       `._,'     _   _             ;   \n"
"        ,'     ,' `-'Hb-.___..._,-'    \n"
"        \\    ,'\"Hb.-'HH`-.dHF\"       \n"  
"         `--'   \"Hb  HH  dF\"           \n"
"                 \"Hb HH dF             \n"
"                  \"HbHHdF              \n"
"                   |HHHF               \n"
"                   |HHH|               \n"
"                   |HHH|               \n"
"                   |HHH|               \n"
"                   |HHH|               \n"
"                   dHHHb               \n"
"                 .dFd|bHb.               o\n"
"       o       .dHFdH|HbTHb.          o /\n"
" \\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
" ##########################################\n";
    outFile.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

    try
    {
        if (this->getStatus() == true)
        {
            if (executor.getGrade() <= this->getExecGrade())
            {
                WriteAsciiTree(this);
                std::cout << this->target << "_shrubbery tree has been created";
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

std::ostream    &operator<<(std::ostream &o, const ShrubberyCreationForm &a)
{
    o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecGrade() <<
	"\n\tis signed:\t" << a.getStatus() <<
	std::endl;
	return (o);
}