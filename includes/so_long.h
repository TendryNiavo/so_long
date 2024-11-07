/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:22:42 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/13 09:22:43 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	void	*img_empty;
	int		map_width;
	int		map_height;
	char	**map;
	int		x;
	int		y;
	int		count_p;
	int		count_e;
	int		count_c;
	int		move;
	int		exit_x;
	int		exit_y;
}		t_data;

int		main(int argc, char **argv);
int		check_map_accessibility(t_data *data);
void	ft_error(char *str);
int		check_arguments(int argc, char **argv);
void	extract_map(char **str, t_data *game);
int		count_char(char c, char *str);
void	free_map(t_data *game);
void	render_map(t_data *game);
int		key_handler(int keycode, t_data *game);
int		exit_game(t_data *game);
void	move_player(t_data *game, int new_x, int new_y);
void	clean_game(t_data *game);
void	set_image(t_data *game);
void	render_map(t_data *game);
void	map_size(t_data *game, char **str);
int		check_arguments(int argc, char **argv);
void	init_game(t_data *game, char **argv);
void	init_player_position(t_data *game);
void	extract_map(char **str, t_data *game);
int		check_map_error(t_data *game);
int		line_check(t_data *game);
int		check_walls(t_data *game);
void	scan_map(t_data *game);
void	check_items(char *str, t_data *game);
char	**copy_map(char **map, int height);
int		check_exit(char **map, int collect_nb, t_data *game);
void	quit_game(t_data *game);

#endif