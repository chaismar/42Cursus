	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:31:47 by lmarchai          #+#    #+#             */
/*   Updated: 2024/02/06 14:47:41 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook{
  public :
	PhoneBook(void);
	~PhoneBook(void);

	int index; 
	Contact repertory[8];
	
	void add(void);
	void search(Contact rep[8]) const;

	private :
};

#endif