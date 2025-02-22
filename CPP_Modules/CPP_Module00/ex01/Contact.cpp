/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:31:15 by lmarchai          #+#    #+#             */
/*   Updated: 2024/01/19 03:37:06 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
    //std::cout << "Contact constructor called\n";
    return ;
}

Contact::~Contact(void)
{
    //std::cout << "Contact destructor called\n";
    return ;
}

std::string Contact::get_first_n(void) const
{
    return (this->first_name);
}

std::string Contact::get_nick_n(void) const
{
    return (this->nickname);
}

std::string Contact::get_last_n(void) const
{
    return (this->last_name);
}

std::string Contact::get_phone_n(void) const
{
    return (this->last_name);
}

std::string Contact::get_dark_s(void) const
{
    return (this->last_name);
}

void    Contact::set_first_n(std::string s)
{
    this->first_name = s;
    return ;
}

void    Contact::set_last_n(std::string s)
{
    this->last_name = s;
    return ;
}

void    Contact::set_nick_n(std::string s)
{
    this->nickname = s;
    return ;
}

void    Contact::set_phone_n(std::string s)
{
    this->phone_number = s;
    return ;
}

void    Contact::set_dark_s(std::string s)
{
    this->darkest_secret = s;
    return ;
}