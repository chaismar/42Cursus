/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:55:31 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/24 15:21:41 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../includes/minilibx-linux/mlx.h"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_collect
{
	int					is_collected;
	t_pos				pos;
	struct s_collect	*next;
}t_collect;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			is_valid;
	t_collect	*collectible;
	t_pos		exit;
	t_pos		start;
}t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	int					moove;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*background_img;
	void				*player_img;
	void				*exit_img;
	void				*collectible_img;
	void				*wall_img;
	void				*inside_wall_img;
	t_pos				moove_set;
	t_pos				player;
	t_img				img;
	t_map				map;
}	t_data;

int		check_dfs(t_map map);
void	free_map(t_map map);
void	free_collectible(t_map map);
int		start_or_exit_error(t_map map);
t_map	add_exit(t_map map, int x, int y);
t_map	add_start(t_map map, int x, int y);
t_map	add_collectible(t_map map, int x, int y);
int		map_width_len(char *file);
int		map_height_len(char *file);
int		map_check_width_line(char *file, int width);
t_map	init_map(t_map map, char *file);
t_map	fill_map(t_map map, char *file);
int		check_wall(t_map map);
t_map	fill_game_object(t_map map);
t_map	depth_first_check(t_map map, t_pos pos);
int		check_right(t_map map, t_pos pos);
int		check_left(t_map map, t_pos pos);
int		check_down(t_map map, t_pos pos);
int		check_up(t_map map, t_pos pos);
int		collectible_error(t_map map);
int		exit_or_collectible_not_available(t_map map);
int		read_error(t_map map);
int		width_error(t_map map);
int		wall_error(t_map map);
void	alloc_error_free(t_map map);
void	alloc_error(t_map map);
t_data	*move_left(t_data *data);
t_data	*move_right(t_data *data);
t_data	*move_down(t_data *data);
t_data	*move_up(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_click_end(t_data *data);
t_map	set_inside_wall(t_map map);
t_map	set_starting_pos(t_map map);
void	init_data_img(t_data *data);
void	init_imgs_null(t_data *data);
void	init_data(t_data *data, t_map map);
int		exit_game(t_data *data);
void	collect_this(t_data *data, t_pos pos);
void	check_collect(t_data *data);
void	print_case(t_data *data, int i, int j);
void	print_map(t_data *data);
int		print_collectibles(t_data *data);
int		print_player(t_data *data);
void	check_end(t_data *data);
void	free_all_1(t_data *data);
void	destroy_img1(t_data *data);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	print_nbr_moove(int i);
void	map_error(t_map map);
#endif