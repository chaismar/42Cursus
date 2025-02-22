#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vect(10);
    int value = 2;
    std::fill(vect.begin(), vect.end(), value);
    std::vector<int>::iterator found = easyfind(vect, 2);
    if (found == vect.end())
        std::cout << "[+]Vector[+]  Error : value not found" << std::endl;
    else
        std::cout << "[+]Vector[+]   Yeah " << *found << " is inside me in " << found - vect.begin() << std::endl;
    if (easyfind(vect, 666) == vect.end())
        std::cout << "[+]Vector[+]   Error : value not found" << std::endl;

    std::deque<int> deq(10);
    for (size_t i = 0; i < 10; i++)
        deq.push_back(2);
    std::deque<int>::iterator founddeq = easyfind(deq, 2);
    if (founddeq == deq.end())
        std::cout << "[+]Deque [+]   Error : value not found" << std::endl;
    else
        std::cout << "[+]Deque [+]   Yeah " << *founddeq << " is inside me in " << founddeq - deq.begin() << std::endl;
    if (easyfind(deq, 666) == deq.end())
        std::cout << "[+]Deque [+]   Error : value not found" << std::endl;

    std::list<int> lst(10);
    for (size_t i = 0; i < 10; i++)
        lst.push_back(2);
    std::list<int>::iterator foundlst = easyfind(lst, 2);
    if (foundlst == lst.end())
        std::cout << "[+] List [+]   Error : value not found" << std::endl;
    else
        std::cout << "[+] List [+]   Yeah " << *foundlst << " is inside me in List lst" << std::endl; //operateur(-) non definis en c++98 pour le type d'iterateur de list 
    if (easyfind(lst, 666) == lst.end())
        std::cout << "[+] List [+]   Error : value not found" << std::endl;
}