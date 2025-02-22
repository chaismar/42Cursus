/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:46:23 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/13 15:27:00 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_tubes_and_files(t_pipex stocker, int i)
{
	if (stocker.infile > -1)
		close(stocker.infile);
	if (stocker.outfile > -1)
		close(stocker.outfile);
	if (i == 1)
	{
		close(stocker.tube[1][0]);
		close(stocker.tube[1][1]);
	}
	else
	{
		close(stocker.tube[0][0]);
		close(stocker.tube[0][1]);
		close(stocker.tube[1][0]);
		close(stocker.tube[1][1]);
	}
	return ;
}

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	child_free(t_pipex stocker)
{
	int	i;

	i = 0;
	while (stocker.cmd_args[i] != NULL)
	{
		free(stocker.cmd_args[i]);
		i++;
	}
	free(stocker.cmd_args);
	free(stocker.cmd);
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
	free(stocker.pid);
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
