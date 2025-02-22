/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:30:56 by lmarchai          #+#    #+#             */
/*   Updated: 2022/12/06 12:56:27 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calc_char(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*final;

	final = malloc((calc_char(n) + 1) * sizeof(char));
	if (!final)
		return (NULL);
	final[calc_char(n)] = '\0';
	while (n > 9)
	{
		final[calc_char(n) - 1] = n % 10 + '0';
		n = n / 10;
	}
	final[0] = n + '0';
	return (final);
}
