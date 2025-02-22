/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:30:19 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/13 15:25:18 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_childs(t_pipex stocker)
{
	waitpid(stocker.pid1, 0, 0);
	waitpid(stocker.pid2, 0, 0);
	close_pipes(stocker);
	close(stocker.infile);
	close(stocker.outfile);
}

void	close_childs(int tube, int infile, int outfile)
{
	close(tube);
	if (infile > -1)
		close(infile);
	if (outfile > -1)
		close(outfile);
}

void	first_child_process(t_pipex stocker, char **argv, char **envp)
{
	dup2(stocker.tube[1], 1);
	close(stocker.tube[0]);
	dup2(stocker.infile, 0);
	stocker.cmd_args = ft_split(argv[2], ' ');
	stocker.cmd = get_cmd(stocker.cmd_paths, stocker.cmd_args[0]);
	if (!stocker.cmd || stocker.infile < 0)
	{
		close_childs(stocker.tube[1], stocker.infile, stocker.outfile);
		child_free(stocker);
		parent_free(stocker);
		if (stocker.infile < 0)
			error_exit(stocker.infile, stocker.outfile, 0);
		msg(ERR_CMD);
		exit(-1);
	}
	execve(stocker.cmd, stocker.cmd_args, envp);
	close(stocker.tube[1]);
	close(stocker.infile);
	close(stocker.outfile);
	child_free(stocker);
	parent_free(stocker);
	msg(ERR_CMD);
	exit(-1);
}

void	second_child_process(t_pipex stocker, char **argv, char **envp)
{
	dup2(stocker.tube[0], 0);
	close(stocker.tube[1]);
	dup2(stocker.outfile, 1);
	stocker.cmd_args = ft_split(argv[3], ' ');
	stocker.cmd = get_cmd(stocker.cmd_paths, stocker.cmd_args[0]);
	if (!stocker.cmd || stocker.outfile < 0)
	{
		close_childs(stocker.tube[0], stocker.infile, stocker.outfile);
		child_free(stocker);
		parent_free(stocker);
		if (stocker.outfile < 0)
			error_exit(stocker.infile, stocker.outfile, 1);
		msg(ERR_CMD);
		exit(-1);
	}
	execve(stocker.cmd, stocker.cmd_args, envp);
	close(stocker.tube[0]);
	close(stocker.infile);
	close(stocker.outfile);
	child_free(stocker);
	parent_free(stocker);
	msg(ERR_CMD);
	exit(-1);
}
