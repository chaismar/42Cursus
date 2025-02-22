#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
	public :
		Brain();
		Brain(const Brain &ref);

		~Brain();

		Brain & operator=(Brain const &rhs);

		std::string *getIdeas(void);
		void setIdeas(std::string val[100]);
	private :
		std::string ideas[100];
};

#endif