#include "Harl.hpp"
#include <iostream>
#include <map>

void Harl::complain(std::string level)
{
    typedef void (Harl::*LevelFunction)(void);
    
    std::map<std::string, LevelFunction> m;
    m["DEBUG"] = &Harl::debug;
    m["INFO"] = &Harl::info;
    m["WARNING"] = &Harl::warning;
    m["ERROR"] = &Harl::error;

    std::map<std::string, LevelFunction>::iterator it = m.find(level);

    if (it != m.end()){
        (this->*(it->second))();
    }
    else
        std::cout << "Level not found" << std::endl; 
}

void Harl::debug(void)
{
    std::cout << "debug" << std::endl;
}

void Harl::info(void)
{
    std::cout << "info" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "warning" << std::endl;
}

void Harl::error(void)
{
    std::cout << "error" << std::endl;
}