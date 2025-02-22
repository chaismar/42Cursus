/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:22:12 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 15:34:36 by lmarchai         ###   ########.fr       */
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
# include "../../includes/minilibx-linux/mlx.h"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_queue
{
	t_pos			pos;
	struct s_queue	*previous;
	struct s_queue	*next;
}	t_queue;

typedef struct s_enemies
{
	t_pos				pos;
	t_pos				next_pos;
	struct s_enemies	*next;
}t_enemies;

typedef struct s_collect
{
	int					is_collected;
	t_pos				pos;
	struct s_collect	*next;
}t_collect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			is_valid;
	t_enemies	*enemies;
	t_collect	*collectible;
	t_pos		exit;
	t_pos		start;
}t_map;

typedef struct s_player_up_img
{
	t_img					*img;
	struct s_player_up_img	*next;
}	t_player_up_img;

typedef struct s_player_down_img
{
	t_img						*img;
	struct s_player_down_img	*next;
}	t_player_down_img;

typedef struct s_player_right_img
{
	t_img						*img;
	struct s_player_right_img	*next;
}	t_player_right_img;

typedef struct s_player_left_img
{
	t_img						*img;
	struct s_player_left_img	*next;
}	t_player_left_img;

typedef struct s_data
{
	int					moove;
	int					frame;
	int					last_key_up_timer;
	int					last_key_down_timer;
	int					last_key_right_timer;
	int					last_key_left_timer;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*background_img;
	void				*player_img;
	void				*exit_img;
	void				*enemie_img;
	void				*collectible_img;
	void				*wall_img;
	void				*inside_wall_img;
	t_player_down_img	*list_down;
	t_player_left_img	*list_left;
	t_player_up_img		*list_up;
	t_player_right_img	*list_right;
	t_pos				moove_set;
	t_pos				player;
	t_img				img;
	t_map				map;
}	t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

char	*ft_itoa(int n);
int		calc_char(int n);
void	print_moove(t_data *data);

int		check_already_checked(t_queue *queue, t_pos next_pos);
int		handle_click_end(t_data *data);

t_queue	*add_next(t_queue *queue, t_pos next_pos);
t_queue	*get_next_nodes(t_data *data, t_queue *queue);

t_pos	get_first_pos(t_queue *queue);
t_pos	bfs(t_data *data, t_enemies enemie);

t_data	*move_up(t_data *data);
t_data	*move_down(t_data *data);
t_data	*move_right(t_data *data);
t_data	*move_left(t_data *data);
t_data	*move_enemie(t_data *data);

t_map	add_exit(t_map map, int x, int y);
t_map	add_start(t_map map, int x, int y);
t_map	add_collectible(t_map map, int x, int y);
t_map	add_enemies(t_map map, int x, int y);
t_map	init_map(t_map map, char *file);
t_map	fill_map(t_map map, char *file);
t_map	fill_game_object(t_map map);
t_map	depth_first_check(t_map map, t_pos pos);
t_map	set_inside_wall(t_map map);
t_map	set_starting_pos(t_map map);

void	init_data_img(t_data *data);
void	init_img(t_data *data);
void	init_data(t_data *data, t_map map);
void	free_collectible(t_map map);
void	free_map(t_map map);
void	print_case(t_data *data, int i, int j);
void	print_map(t_data *data);
void	movement_up(t_data *data);
void	movement_down(t_data *data);
void	movement_right(t_data *data);
void	movement_right(t_data *data);
void	movement_left(t_data *data);
void	init_up_img(t_data *data);
void	init_down_img(t_data *data);
void	init_left_img(t_data *data);
void	init_right_img(t_data *data);
void	incr_frame(t_data *data);
void	collect_this(t_data *data, t_pos pos);
void	check_end(t_data *data);
void	check_collect(t_data *data);
void	get_next_pos(t_data *data);
void	free_enemies(t_map map);
void	get_next_pos(t_data *data);
void	alloc_error_free(t_map map);
void	destroy_img1(t_data *data);
void	destroy_img2(t_data *data);
void	destroy_img3(t_data *data);
void	free_all_1(t_data *data);
void	free_all_2(t_data *data);
void	alloc_error(t_map map);
void	alloc_error_free(t_map map);
void	map_error(t_map map);

int		exit_game(t_data *data);
int		exit_or_collectible_not_available(t_map map);
int		width_error(t_map map);
int		start_or_exit_error(t_map map);
int		collectible_error(t_map map);
int		read_error(t_map map);
int		wall_error(t_map map);
int		check_wall(t_map map);
int		check_dfs(t_map map);
int		map_check_width_line(char *file, int width);
int		map_width_len(char *file);
int		map_height_len(char *file);
int		print_player(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		game(t_data *data);
int		start_game(t_map map);
int		print_collectibles(t_data *data);
int		check_enemi_end(t_data *data);
int		print_enemie(t_data *data);
int		check_bfs_end(t_queue *queue, t_pos goal);
int		main(int argc, char **argv);

#endif