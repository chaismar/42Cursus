#include "RPN.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include <ios>

static float add(float f1, float f2)
{
	return f1 + f2;
}
static float sous(float f1, float f2)
{
	return f1 - f2;
}
static float mult(float f1, float f2)
{
	return f1 * f2;
}
static float div(float f1, float f2)
{
	return f1 / f2;
}

static float ft_stof(std::string s)
{
	std::istringstream iss(s);
	float f;
	iss >> f;
	return f;
}

void RPN::calc()
{

	float (*functptr[])(float, float) = {add, sous, mult, div} ;
	std::string toFind = "+-*/";
	std::istringstream iss;

	iss.str(_s.substr(4));
	float f1;
	float f2;

	for(std::string word; iss >> word;)
	{
		if (toFind.find(word) < std::string::npos)
		{
			f1 = _stack.top();
			_stack.pop();
			f2 = _stack.top();
			_stack.pop();
			_stack.push((*functptr[toFind.find(word)])(f2, f1)); 
		}
		else
			_stack.push(ft_stof(word));
	}
	std::cout << _stack.top() << std::endl;
}

RPN::RPN(std::string s)
{
	float f;
	
	std::istringstream iss;
	iss.str(s);
	iss >> f;
	_stack.push(f);
	iss >> f;
	_stack.push(f);
	_s = s;
}


RPN::~RPN()
{

}

