/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:31:23 by lmarchai          #+#    #+#             */
/*   Updated: 2024/01/19 03:31:24 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact{
	public :
	Contact(void);
	~Contact(void);

	std::string get_first_n(void) const;
	std::string get_last_n(void) const;
	std::string get_nick_n(void) const;
	std::string get_phone_n(void) const;
	std::string get_dark_s(void) const;
	void set_first_n(std::string s);
	void set_last_n(std::string s);
	void set_nick_n(std::string s);
	void set_phone_n(std::string s);
	void set_dark_s(std::string s);

	private :
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif