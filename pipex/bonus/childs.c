/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:13:51 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/13 15:32:14 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	wait_childs(t_pipex stocker)
{
	int		i;

	i = 0;
	while (i < stocker.nbr_cmd - 1)
	{
		waitpid(stocker.pid[i], 0, 0);
		i++;
	}
	return (0);
}

void	first_child(t_pipex stocker, char **argv, char **envp)
{	
	dup2(stocker.tube[1][1], 1);
	close(stocker.tube[1][0]);
	dup2(stocker.infile, 0);
	stocker.cmd_args = ft_split(argv[2 + stocker.heredoc], ' ');
	stocker.cmd = get_cmd(stocker.cmd_paths, stocker.cmd_args[0]);
	if (!stocker.cmd || stocker.infile < 0)
	{
		child_free(stocker);
		parent_free(stocker);
		close_tubes_and_files(stocker, 1);
		if (stocker.infile < 0)
			error_exit(stocker.infile, stocker.outfile, 0);
		msg(ERR_CMD);
		exit(1);
	}
	execve(stocker.cmd, stocker.cmd_args, envp);
	child_free(stocker);
	parent_free(stocker);
	close_tubes_and_files(stocker, 1);
	msg(ERR_CMD);
	exit(1);
}

void	child(t_pipex stocker, char **argv, char **envp, int nbr_to_do)
{
	stocker.cmd_args = ft_split(argv[nbr_to_do + stocker.heredoc], ' ');
	stocker.cmd = get_cmd(stocker.cmd_paths, stocker.cmd_args[0]);
	dup2(stocker.tube[0][0], 0);
	close(stocker.tube[0][1]);
	dup2(stocker.tube[1][1], 1);
	close(stocker.tube[1][0]);
	if (!stocker.cmd || !stocker.cmd_args)
	{
		child_free(stocker);
		parent_free(stocker);
		close_tubes_and_files(stocker, 2);
		if (stocker.outfile < 0)
			error_exit(stocker.infile, stocker.outfile, 1);
		msg(ERR_CMD);
		exit(1);
	}
	execve(stocker.cmd, stocker.cmd_args, envp);
	child_free(stocker);
	parent_free(stocker);
	close_tubes_and_files(stocker, 2);
	msg(ERR_CMD);
	exit(1);
}

void	last_child(t_pipex stocker, char **argv, char **envp)
{
	stocker.cmd_args = ft_split(argv[stocker.nbr_cmd], ' ');
	stocker.cmd = get_cmd(stocker.cmd_paths, stocker.cmd_args[0]);
	dup2(stocker.tube[0][0], 0);
	close(stocker.tube[0][1]);
	dup2(stocker.outfile, 1);
	if (!stocker.cmd || stocker.outfile < 0)
	{
		child_free(stocker);
		parent_free(stocker);
		close_tubes_and_files(stocker, 2);
		if (stocker.outfile < 0)
			error_exit(stocker.infile, stocker.outfile, 1);
		msg(ERR_CMD);
		exit(1);
	}
	execve(stocker.cmd, stocker.cmd_args, envp);
	child_free(stocker);
	parent_free(stocker);
	close_tubes_and_files(stocker, 2);
	msg(ERR_CMD);
	exit(1);
}
