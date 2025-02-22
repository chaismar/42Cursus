#include <iostream>
#include "Span.hpp"
#include <vector>

int main()
{
    try
    {
        Span sp(5);

        // Ajouter des nombres au Span
        sp.addNumber(17);
        sp.addNumber(3);
        sp.addNumber(11);
        sp.addNumber(9);
        sp.addNumber(6);

        // Afficher les plus courts et longs écarts
        std::cout << "sp Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "sp Longest Span: " << sp.longestSpan() << std::endl;

        // Test de l'exception quand le Span est plein
        // sp.addNumber(42); // Cela devrait lancer une exception
            
        // Test avec un intervalle d'itérateurs
        std::vector<int> moreNumbers;
        for (size_t i = 0; i < 10000; i++)
            moreNumbers.push_back(i);
        Span sp2(10000);
        sp2.addNumber(moreNumbers.begin(), moreNumbers.end());
        std::cout << "sp2 Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "sp2 Longest Span: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
