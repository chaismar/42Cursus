/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:06:53 by lmarchai          #+#    #+#             */
/*   Updated: 2022/11/30 19:24:09 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_hex_value_min(unsigned long nbr, int *size)
{
	char	*str;

	if (nbr == 0)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '0';
		*size += 1;
		return (str);
	}
	str = ft_itoa_hex(nbr, HEXA_VAL_MIN);
	*size += ft_strlen(str);
	return (str);
}

char	*get_hex_value(unsigned long nbr, int *size)
{
	char	*str;

	if (nbr == 0)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '0';
		*size += 1;
		return (str);
	}
	str = ft_itoa_hex(nbr, HEXA_VAL);
	*size += ft_strlen(str);
	return (str);
}
