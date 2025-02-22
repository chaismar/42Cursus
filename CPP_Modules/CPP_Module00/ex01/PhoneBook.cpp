/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:31:41 by lmarchai          #+#    #+#             */
/*   Updated: 2024/01/19 03:31:42 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"
#include <sstream>
#include <string.h>

PhoneBook::PhoneBook (void){
    std::cout << "PhoneBook constructor called \n";

    index = 0;
    return ;
}

PhoneBook::~PhoneBook (void){
    std::cout << "PhoneBook destructor called \n";
    return ;
}

std::string format_to_add(std::string to_add)
{
    if (to_add.length() >= 10)
    {
        to_add.replace(9,1,".");
        to_add.erase(10, to_add.length() + 10);
    }
    else
    {
        to_add.insert(0, "           ", 10 - to_add.length());
    }
    to_add += "|";
    return (to_add);
}

std::string pick_contact(Contact rep, int i)
{
    std::string ret;
    std::string to_add;
    std::stringstream stream;

    stream << i + 1;
    stream >> to_add;
    ret += "        ";
    ret += to_add;
    ret += '|';
    to_add = rep.get_first_n();
    ret += format_to_add(to_add);
    to_add = rep.get_nick_n(); 
    ret += format_to_add(to_add);
    to_add = rep.get_last_n();
    ret += format_to_add(to_add);
    ret += "\n";
    return (ret);
}

//pas besoin de passer rep a la fonction 
void PhoneBook::search (Contact rep[8]) const
{
    char buff[512];
    int j;

    if (index <= 0)
    {
        std::cout << "Ajoutez un contact avant d'utiliser SEARCH\n";    
        return ;
    }
    if (index >= 8)
        j = 8;
    else
        j = index % 8;
    std::cout << "  index  |first name|last name | nickname |\n";
    for(int i = 0; i < j; i++)
        std::cout << pick_contact(rep[i], i);
    std::cout << "Quel contact souhaitez vous chercher \n";
    std::cin >> buff; 
    if (atoi(buff) <= 0 || atoi(buff) > 8)
        std::cout << "Erreur index recommencer\n";
    else
    {
        std::cout << rep[atoi(buff) - 1].get_first_n() << "\n";
        std::cout << rep[atoi(buff) - 1].get_last_n() << "\n";
        std::cout << rep[atoi(buff) - 1].get_nick_n() << "\n";
        std::cout << rep[atoi(buff) - 1].get_phone_n() << "\n";
        std::cout << rep[atoi(buff) - 1].get_dark_s() << "\n";
    }
    return ;
}

void PhoneBook::add(void) 
{
    char buff[512];
    int i  = index % 8;

    std::cout << "Entrer le prénom de votre nouveau contact\n";
    std::cin >> buff;
    repertory[i].set_first_n(buff);

    std::cout << "Entrer le nom de votre nouveau contact\n";
    std::cin >> buff;
    repertory[i].set_last_n(buff);

    std::cout << "Entrer le surnomn de votre nouveau contact\n";
    std::cin >> buff;
    repertory[i].set_nick_n(buff);

    std::cout << "Entrer le numéro de téléphone de votre nouveau contact\n";
    std::cin >> buff;
    repertory[i].set_phone_n(buff);

    std::cout << "Entrer le secret le plus sombre de votre nouveau contact\n";
    std::cin >> buff;
    repertory[i].set_dark_s(buff);
    index++;
    return ;
}
