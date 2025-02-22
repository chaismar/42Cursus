#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
	public :
		RPN(std::string);
		~RPN();
		std::stack<float> _stack;
		std::string _s;
		void calc();
};

#endif