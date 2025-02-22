/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:46:32 by lmarchai          #+#    #+#             */
/*   Updated: 2022/11/20 18:24:19 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*newsrc;
	int		len_src;
	int		i;

	if (!src)
		return ("");
	len_src = ft_strlen(src);
	newsrc = malloc(len_src * sizeof(char) + 1);
	if (!newsrc)
		return (NULL);
	i = 0;
	while (i < len_src)
	{
		newsrc[i] = src[i];
		i++;
	}
	newsrc[i] = '\0';
	return (newsrc);
}

char	*fill_stash(char *stash, char *ex_stash, char *buffer, int *read_size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ex_stash[0] != '\0')
	{
		while (ex_stash[i])
		{
			stash[i] = ex_stash[i];
			i++;
		}
	}
	while (j < *read_size)
	{
		stash[i + j] = buffer[j];
		j++;
	}
	stash[i + j] = '\0';
	return (stash);
}

char	*init_stash(char *stash, int fd, char *buffer, int *read_size)
{
	char	*temp;

	if (fd == -1)
		return (NULL);
	*read_size = read(fd, buffer, BUFFER_SIZE);
	if (!*read_size || *read_size == -1)
		return (stash);
	if (!stash)
		stash = malloc(sizeof(char) * *read_size + 1);
	else
	{
		temp = ft_strdup(stash);
		free(stash);
		stash = malloc(sizeof(char) * ft_strlen(temp) + *read_size + 1);
		fill_stash(stash, temp, buffer, read_size);
		return (free(temp), stash);
	}
	fill_stash(stash, "", buffer, read_size);
	return (stash);
}
