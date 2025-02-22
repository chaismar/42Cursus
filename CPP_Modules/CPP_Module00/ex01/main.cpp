/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:31:31 by lmarchai          #+#    #+#             */
/*   Updated: 2024/02/07 11:51:23 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstring>

int main()
{
    char buff[512];
    PhoneBook myphone;

    while (1)
    {
        std::cout << "______________________________________________\n";
        std::cout << "Pour ajouter un contact tappé : \"ADD\"\n";
        std::cout << "Pour chercher un contact tappé : \"SEARCH\"\n";
        std::cout << "Pour quitter tappé : \"EXIT\"\n";
        std::cout << "______________________________________________\n";
        std::cin >> buff;
        std::cout << "\n\n\n\n\n";
        if (strcmp(buff, "ADD") == 0)
            myphone.add();
        else if (strcmp(buff, "SEARCH") == 0)
            myphone.search(myphone.repertory);
        else if (strcmp(buff, "EXIT") == 0)
            return (0);
        else
            std::cout << buff << " n'est pas un mot clé merci de recommencer" << std::endl;
    }
    return (0);
}