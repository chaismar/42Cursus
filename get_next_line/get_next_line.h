/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:06:52 by lmarchai          #+#    #+#             */
/*   Updated: 2022/11/19 20:05:55 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strlen(char *s);
char	*ft_strdup(char *src);
int		find_next_line(char *buffer, int read_size);
char	*fill_stash(char *stash, char *ex_stash, char *buffer, int *read_size);
char	*discharge_stash(char *stash);
char	*get_line(char *stash);
char	*init_stash(char *stash, int fd, char *buffer, int *read_size);
char	*get_next_line(int fd);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif