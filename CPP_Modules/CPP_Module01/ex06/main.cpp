#include "Harl.hpp"
#include <map>

int main(int ac, const char **av) {
    
    if (ac != 2)
    {
        std::cout << "Be cool with Harl\n";    
        return (1);
    }

    Harl harl;
    std::string level(av[1]);
    std::map<std::string, int> m;
    m["DEBUG"] = 0;
    m["INFO"] = 1;
    m["WARNING"] = 2;
    m["ERROR"] = 3;

    std::map<std::string, int>::iterator it = m.find(level);
    if(it == m.end())
        return (harl.complain("UNKNOWN"), 0);
    switch (it->second)
    {
        case 0:
            harl.complain("DEBUG");
            harl.complain("INFO");
            harl.complain("WARNING");
            harl.complain("ERROR");
            break ;

        case 1:
            harl.complain("INFO");
            harl.complain("WARNING");
            harl.complain("ERROR");
            break ;

        case 2:
            harl.complain("WARNING");
            harl.complain("ERROR");
            break ;

        case 3:
            harl.complain("ERROR");
            break ;

        default:
            harl.complain("UNKNOWN");
            break;
    }
    return 0;
}