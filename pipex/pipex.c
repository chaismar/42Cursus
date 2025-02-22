/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:38:35 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 15:03:23 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex2(t_pipex stocker, char **argv, char **envp)
{
	stocker.paths = find_path(envp);
	if (stocker.paths)
		stocker.cmd_paths = ft_split(stocker.paths, ':');
	else
		stocker.cmd_paths = NULL;
	stocker.pid1 = fork();
	if (stocker.pid1 == 0)
		first_child_process(stocker, argv, envp);
	stocker.pid2 = fork();
	if (stocker.pid2 == 0)
		second_child_process(stocker, argv, envp);
	close_pipes(stocker);
	wait_childs(stocker);
	parent_free(stocker);
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	t_pipex	stocker;

	stocker.infile = f1;
	stocker.outfile = f2;
	if (pipe(stocker.tube) < 0)
		error_exit(f1, f2, 2);
	pipex2(stocker, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipex(open(argv[1], O_RDONLY), open(argv[4], \
		O_CREAT | O_TRUNC | O_RDWR, 0777), argv, envp);
	else
	{
		write(2, "Error : args\n", 14);
		return (1);
	}
	return (0);
}
