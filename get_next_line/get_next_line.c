/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:03:31 by lmarchai          #+#    #+#             */
/*   Updated: 2022/11/20 18:36:04 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*discharge_stash(char *stash)
{
	int		j;
	int		total_size;
	int		size_line;
	char	*temp;

	if (!stash)
		return (NULL);
	total_size = ft_strlen(stash);
	size_line = 0;
	j = 0;
	while (stash[size_line] != '\n' && stash[size_line])
		size_line++;
	size_line++;
	temp = malloc(total_size - size_line + 2);
	while (size_line < total_size)
	{
		temp[j++] = stash[size_line];
		size_line++;
	}
	temp[j] = '\0';
	free(stash);
	stash = ft_strdup(temp);
	if (ft_strlen(stash) == 0)
		return (free(stash), free(temp), NULL);
	return (free(temp), stash);
}

char	*get_line(char *stash)
{
	int		size_line;
	int		j;
	char	*line;

	size_line = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[size_line] != '\n' && stash[size_line])
		size_line++;
	line = malloc(sizeof(char) * size_line + 2);
	while (j <= size_line)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}

int	find_next_line(char *buffer, int read_size)
{
	int	i;

	if (buffer != NULL)
	{
		i = 0;
		while (i < read_size)
		{
			if (buffer[i] == 0 || buffer[i] == '\n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

char	*get_next_line2(char *stash, char *buffer, int *read_size, int fd)
{
	char	*temp;

	while (find_next_line(buffer, *read_size) && *read_size > 0)
	{
		temp = ft_strdup(stash);
		free(stash);
		stash = malloc(sizeof(char) * ft_strlen(temp) + *read_size + 1);
		if (!stash)
			return (free(temp), NULL);
		stash = fill_stash(stash, temp, buffer, read_size);
		free(temp);
		*read_size = read(fd, buffer, BUFFER_SIZE);
		if (*read_size == -1)
			return (free(stash), NULL);
	}
	if (*read_size > 0)
	{
		temp = ft_strdup(stash);
		free(stash);
		stash = malloc(sizeof(char) * ft_strlen(temp) + *read_size + 1);
		stash = fill_stash(stash, temp, buffer, read_size);
		free(temp);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*temp;
	int			read_size;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read_size = 0;
	stash = init_stash(stash, fd, buffer, &read_size);
	while (read_size > 0 && find_next_line(stash, ft_strlen(stash)) != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		stash = get_next_line2(stash, buffer, &read_size, fd);
		if (find_next_line(stash, ft_strlen(stash)) == 0)
		{
			temp = get_line(stash);
			stash = discharge_stash(stash);
			return (free(buffer), temp);
		}
	}
	temp = get_line(stash);
	stash = discharge_stash(stash);
	return (free(buffer), temp);
}
