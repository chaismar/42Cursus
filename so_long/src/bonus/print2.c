/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:38:45 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 14:48:58 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moove(t_data *data)
{
	char	*to_print;

	to_print = ft_itoa(data->moove);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 35, 000000, to_print);
	free(to_print);
	data->moove++;
	to_print = ft_itoa(data->moove);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 35, 0xFFFFFF, to_print);
	free(to_print);
}

int	calc_char(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*final;
	int		neg;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	final = malloc((calc_char(n) + neg + 1) * sizeof(char));
	if (!final)
		return (NULL);
	final[calc_char(n) + neg] = '\0';
	if (neg == 1)
		final[0] = '-';
	while (n > 9)
	{
		final[calc_char(n) + neg - 1] = n % 10 + '0';
		n = n / 10;
	}
	final[neg] = n + '0';
	return (final);
}
