/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:23:43 by lmarchai          #+#    #+#             */
/*   Updated: 2023/05/17 12:14:29 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_access_file(t_pipex stocker, char **files, int f1, int f2)
{
	int	i;

	i = 0;
	while (files[i] != NULL)
		i++;
	if ((access(files[1], F_OK & R_OK & W_OK) == 0 && f1 > 0)
		|| (stocker.heredoc == 1))
	{
		if (access(files[i - 1], F_OK & R_OK & W_OK) == 0 && f2 > 0)
			return (0);
	}
	return (1);
}

t_pipex	new_pipe(t_pipex stocker, int i)
{
	if (i != 1)
	{
		close(stocker.tube[0][0]);
		close(stocker.tube[0][1]);
	}
	stocker.tube[0][0] = stocker.tube[1][0];
	stocker.tube[0][1] = stocker.tube[1][1];
	if (pipe(stocker.tube[1]) != 0)
	{
		parent_free(stocker);
		exit(0);
	}
	return (stocker);
}

char	*find_path(char **envp)
{
	if (!envp[0])
		return (NULL);
	while (ft_strncmp("PATH", *envp, 4))
	{
		envp++;
		if (!*envp)
			return (NULL);
	}
	return (*envp + 5);
}

char	*nopath(char *cmd)
{
	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK | X_OK) == 0)
		{
			return (cmd);
		}
	}
	return (NULL);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*to_try;

	if (!cmd)
		return (NULL);
	if (!paths)
		return (nopath(cmd));
	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		to_try = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(to_try, 0) == 0)
			return (to_try);
		free(to_try);
		paths++;
	}
	return (NULL);
}
