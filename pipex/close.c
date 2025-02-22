/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:27:27 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/13 15:17:50 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_free(t_pipex stocker)
{
	int	i;

	i = 0;
	if (stocker.cmd)
		free(stocker.cmd);
	while (stocker.cmd_args[i] != NULL)
	{
		free(stocker.cmd_args[i]);
		i++;
	}
	free(stocker.cmd_args);
}

void	parent_free(t_pipex	stocker)
{
	int	i;

	i = 0;
	if (stocker.paths)
	{
		while (stocker.cmd_paths[i] != NULL)
		{
			free(stocker.cmd_paths[i]);
			i++;
		}
		free(stocker.cmd_paths);
	}
}

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	close_pipes(t_pipex stocker)
{
	close(stocker.tube[0]);
	close(stocker.tube[1]);
}

void	error_exit(int f1, int f2, int i)
{
	if (f1 != -1)
		close(f1);
	if (f2 != -1)
		close(f2);
	if (i == 0)
		write(2, "Error Infile\n", 13);
	if (i == 1)
		write(2, "Error Outfile\n", 14);
	if (i == 2)
		write(2, "Pipe Error\n", 11);
	if (i == 3)
		write(2, "No environement\n", 16);
	exit(1);
}
