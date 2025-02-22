/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:40:24 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/15 13:53:22 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft/libft.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

int		msg(char *err);
int		check_access_file(char *file);
void	close_pipes(t_pipex stocker);
char	*get_cmd(char **paths, char *cmd);
char	*find_path(char **envp);
void	child_free(t_pipex stocker);
void	parent_free(t_pipex	stocker);
void	first_child_process(t_pipex stocker, char **argv, char **envp);
void	second_child_process(t_pipex stocker, char **argv, char **envp);
void	wait_childs(t_pipex stocker);
void	error_exit(int f1, int f2, int i);
void	pipex(int f1, int f2, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

#endif