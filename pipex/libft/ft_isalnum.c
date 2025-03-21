/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:57 by lmarchai          #+#    #+#             */
/*   Updated: 2022/11/07 12:11:57 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	return ((i >= '0' && i <= '9' ) || (i >= 'a' && i <= 'z')
		|| (i >= 'A' && i <= 'Z'));
}
