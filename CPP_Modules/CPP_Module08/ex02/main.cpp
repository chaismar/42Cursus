#include "MutantStack.hpp"
#include <stack>
#include <list>


void	test_subject() {
	std::cout << "=== Test subject ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	std::cout << "push 5" << std::endl;
	mstack.push(17);
	std::cout << "push 17" << std::endl;

	std::cout << "top of the list : "<< mstack.top() << std::endl;

	mstack.pop();
	std::cout << "popped (17)" << std::endl;

	std::cout << "list size : ";
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	std::cout << "push 3" << std::endl;
	mstack.push(5);
	std::cout << "push 5" << std::endl;
	mstack.push(737);
	std::cout << "push 737" << std::endl;
	//[...]
	mstack.push(0);
	std::cout << "push 0" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "print stack :" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;
}

void	test_list() {
std::cout << "=== Test list ===" << std::endl;
	std::list<int> list;

	list.push_back(5);
	std::cout << "push back 5" << std::endl;
	list.push_back(17);
	std::cout << "push back 17" << std::endl;

	std::cout << "back of the list : "<< list.back() << std::endl;

	list.pop_back();
	std::cout << "popped back (17)" << std::endl;

	std::cout << "list size : ";
	std::cout << list.size() << std::endl;
	list.push_back(3);
	std::cout << "push back 3" << std::endl;
	list.push_back(5);
	std::cout << "push back 5" << std::endl;
	list.push_back(737);
	std::cout << "push back 737" << std::endl;
	//[...]
	list.push_back(0);
	std::cout << "push back 0" << std::endl;

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;
	std::cout << "print list :" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(list);
	std::cout << std::endl;
}

int main() {
	test_subject();
	test_list();

	return 0;
}