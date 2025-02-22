/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:44:12 by lmarchai          #+#    #+#             */
/*   Updated: 2023/05/05 11:45:22 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	total_ascii(char **argv)
{
	long	total;
	int		i;
	int		j;

	total = 1;
	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			total += argv[i][j];
			j++;
		}
		i++;
	}
	total = total * total;
	return (total);
}

char	*seeded_word(long nbr, char *alnum)
{
	char	*word;
	int		i;

	word = malloc((nbr / 10) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (nbr > 0)
	{
		word[i] = alnum[nbr % 36];
		nbr = nbr / 12;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*add_char(char *s, char c)
{
	int				len_tot;
	unsigned int	i;
	char			*res;

	if (s[0] == '\0')
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		return (res[0] = c, res[1] = 0, res);
	}
	len_tot = ft_strlen(s);
	res = malloc(sizeof(char) * len_tot + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	return (free(s), res);
}

int	heredoc2(char *limiter, int fd)
{
	char	buf[1];
	char	*lign;

	buf[0] = 0;
	while (1)
	{
		lign = "";
		write(1, "heredoc> ", 10);
		while (buf[0] != '\n')
		{
			read(0, buf, 1);
			lign = add_char(lign, buf[0]);
		}
		if (ft_strncmp(lign, limiter, ft_strlen(limiter)) == 0
			&& lign[ft_strlen(limiter)] == '\n')
			return (free(lign), fd);
		else
		{
			write(fd, lign, ft_strlen(lign));
			buf[0] = '\0';
		}
		free(lign);
	}
	return (free(lign), fd);
}

int	heredoc(char *limiter, char **argv, int argc)
{
	int		fd;
	char	*lign;

	if (argc < 6)
	{
		write(2, "Error : not enough args\n", 24);
		exit (-1);
	}
	lign = seeded_word(total_ascii(argv),
			"abcdefghijklmnopqrstuvwxyz0123456789");
	if (!lign)
		return (-1);
	lign = ft_strjoin_free(lign, ".seed");
	if (!lign)
		return (free(lign), -1);
	fd = open(lign, O_CREAT | O_RDWR | O_TRUNC, 0666);
	heredoc2(limiter, fd);
	close(fd);
	fd = open(lign, O_RDWR);
	return (free(lign), fd);
}
