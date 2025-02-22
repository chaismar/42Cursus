/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:00:15 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/15 13:53:25 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define ERR_CMD "Command not found\n"

typedef struct s_pipex
{
	pid_t	*pid;
	int		heredoc;
	int		nbr_cmd;
	int		tube[2][2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

/*
each child process
*/
void	first_child(t_pipex stocker, char **argv, char **envp);
void	child(t_pipex stocker, char **argv, char **envp, int nbr_to_do);
void	last_child(t_pipex stocker, char **argv, char **envp);
/*
free and close tubes function call before exit parent process 
or child if error occurs
*/

void	close_tubes_and_files(t_pipex stocker, int i);
void	child_free(t_pipex stocker);
void	parent_free(t_pipex	stocker);
void	free_args(char **argv);
void	error_exit(int f1, int f2, int i);

//check if the files have the right access
int		check_access_file(t_pipex stocker, char **files, int f1, int f2);

/*
function that shift or get a path to send the right string to execve
*/

char	*find_path(char **envp);
char	*get_cmd(char **paths, char *cmd);

//function that create a new pipe and remove the older one

t_pipex	new_pipe(t_pipex stocker, int i);

//function that init the t_pipex struct

t_pipex	init_stocker(char **argv, char **envp, t_pipex stocker);

//function that right a message in the terminal stderror

int		msg(char *err);

//function waiting for all child to end

int		wait_childs(t_pipex stocker);

//function that call every function in the process

void	pipex(int f1, int f2, char **argv, char **envp);
void	pipex2(t_pipex stocker, int i, char **argv, char **envp);

/*
function to create a string thanks to argv total
*/

int		total_ascii(char **argv);
char	*seeded_word(long nbr, char *alnum);

/*
function related to here_doc
*/
char	*add_char(char *s, char c);
char	*ft_strjoin_free(char *s1, char *s2);
int		heredoc2(char *limiter, int fd);
int		heredoc(char *limiter, char **argv, int argc);

int		main(int argc, char **argv, char **envp);
#endif