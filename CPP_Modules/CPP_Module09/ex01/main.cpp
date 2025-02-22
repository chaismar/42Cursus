#include <iostream>
#include "RPN.hpp"

#define ER_ARGS std::cerr << "ERROR : number of args is wrong" << std::endl
#define ERR std::cerr << "ERROR"


int check_val(char c)
{
	std::string s = "0123456789-+*/";

	if (s.find(c) > std::string::npos)
		return (1);
	return (0);
}

int check_first_digits(std::string s)
{
	std::string op = "-+*/";

	if (op.find(s.substr(0,1)) < 5)
		return ERR, 1;
	if (op.find(s.substr(2,1)) < 5)
		return ERR, 1;
	return 0;
}

int parse(char *str)
{
	std::string s = str;
	if (check_first_digits(s) == 1)
		return (1);
	for(std::size_t i = 0; i < s.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (check_val(str[i]) == 1)
				return (ERR, 1);
		}
		else
			if (s.substr(i, 1) != " ")
				return (ERR, 1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return ER_ARGS, 1;
	if (parse(av[1]) == 1)
		return (1);
	RPN RPN(av[1]);
	RPN.calc();
	return (0);
}