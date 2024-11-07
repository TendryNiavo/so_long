/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:34:28 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 10:31:38 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_image(t_data *game)
{
	int	i;
	int	j;

	game->img_collect = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/collect.XPM", &i, &j);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/floor.XPM", &i, &j);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/player.XPM", &i, &j);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/wall.XPM", &i, &j);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/exit.XPM", &i, &j);
}

static void	put_img(t_data *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr,
			game->mlx_win, game->img_wall, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->mlx_win, game->img_collect, x * 64, y * 64);
		game->count_c++;
	}
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_floor, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_player, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_exit, x * 64, y * 64);
}

void	render_map(t_data *game)
{
	int	x;
	int	y;

	game->count_c = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width && game->map[y][x])
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}
