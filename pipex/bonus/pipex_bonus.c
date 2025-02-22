/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:00:19 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 15:16:15 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**del_first_cmd(char **argv)
{
	argv[2] = NULL;
	return (argv);
}

t_pipex	init_stocker(char **argv, char **envp, t_pipex stocker)
{
	stocker.nbr_cmd = 0;
	stocker.paths = find_path(envp);
	if (stocker.paths)
		stocker.cmd_paths = ft_split(stocker.paths, ':');
	else
		stocker.cmd_paths = NULL;
	while (argv[stocker.nbr_cmd] != NULL)
		stocker.nbr_cmd++;
	stocker.nbr_cmd -= 2;
	if (stocker.infile == -1)
		argv = del_first_cmd(argv);
	stocker.pid = malloc(sizeof(int) * stocker.nbr_cmd);
	if (!stocker.pid)
		stocker.pid = 0;
	ft_memset(stocker.pid, 0, sizeof(int) * stocker.nbr_cmd);
	if (!stocker.pid)
	{
		parent_free(stocker);
		close_tubes_and_files(stocker, 0);
		exit(0);
	}
	return (stocker);
}

void	pipex2(t_pipex stocker, int i, char **argv, char **envp)
{
	int	pid;

	while (i < stocker.nbr_cmd - (2 + stocker.heredoc))
	{
		stocker = new_pipe(stocker, i);
		pid = fork();
		if (pid != 0)
			stocker.pid[i] = pid;
		else
			child(stocker, argv, envp, i + 2);
		i++;
	}
	stocker = new_pipe(stocker, i);
	pid = fork();
	if (pid == 0)
		last_child(stocker, argv, envp);
	stocker.pid[i] = pid;
	close_tubes_and_files(stocker, 2);
	wait_childs(stocker);
	parent_free(stocker);
	return ;
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		i;
	int		pid;
	t_pipex	stocker;

	i = 1;
	if (ft_strncmp (argv[1], "here_doc", 9) == 0)
		stocker.heredoc = 1;
	else
		stocker.heredoc = 0;
	stocker.infile = f1;
	stocker.outfile = f2;
	stocker = init_stocker(argv, envp, stocker);
	if (pipe(stocker.tube[1]) != 0)
		return (close_tubes_and_files(stocker, 1), parent_free(stocker));
	pid = fork();
	if (pid == 0)
		first_child(stocker, argv, envp);
	stocker.pid[0] = pid;
	pipex2(stocker, i, argv, envp);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int	heredoc_check;

	if (argv[1] && argv[2])
		heredoc_check = ft_strncmp (argv[1], "here_doc", 9);
	if (argc > 4)
	{
		if (heredoc_check == 0)
		{
			heredoc_check = heredoc(argv[2], argv, argc);
			if (heredoc_check != -1)
				pipex(heredoc_check, open(argv[argc - 1],
						O_CREAT | O_RDWR | O_APPEND, 0666), argv, envp);
			else
				write(2, "Error : heredoc error\n", 23);
		}
		else if (access(argv[1], F_OK & R_OK & W_OK) == 0)
			pipex(open(argv[1], O_RDONLY), open(argv[argc - 1], \
			O_CREAT | O_TRUNC | O_RDWR, 0666), argv, envp);
		else
			write(2, "Error : no such file or directory\n", 34);
	}
	else
		return (write(2, "Error : not enough args\n", 25), 1);
	return (0);
}
