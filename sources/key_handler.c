/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:27:31 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 13:49:07 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_data *game)
{
	clean_game(game);
	return (0);
}

void	clean_game(t_data *game)
{
	free_map(game);
	mlx_destroy_image(game->mlx_ptr, game->img_floor);
	mlx_destroy_image(game->mlx_ptr, game->img_player);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_collect);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(1);
}

void	move_player(t_data *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->count_c--;
	if (game->map[new_y][new_x] == 'E' && game->count_c != 0)
		return ;
	if (game->map[new_y][new_x] == 'E' && game->count_c == 0)
	{
		ft_putstr("You Win !\n");
		exit_game(game);
	}
	game->map[game->y][game->x] = '0';
	game->map[new_y][new_x] = 'P';
	if (game->y != new_y || game->x != new_x)
	{
		game->move++;
		ft_putnbr_fd(game->move, 1);
		write(1, "\n", 1);
	}
	game->x = new_x;
	game->y = new_y;
	render_map(game);
}

int	key_handler(int keycode, t_data *game)
{
	int	new_x;
	int	new_y;

	new_x = game->x;
	new_y = game->y;
	if (keycode == XK_Escape)
		exit_game(game);
	else if (keycode == XK_Up || keycode == 119)
		new_y -= 1;
	else if (keycode == XK_Down || keycode == 115)
		new_y += 1;
	else if (keycode == XK_Left || keycode == 97)
		new_x -= 1;
	else if (keycode == XK_Right || keycode == 100)
		new_x += 1;
	if (game->map[new_y][new_x] == 'E' && game->count_c != 0)
		return (1);
	if (game->map[new_y][new_x] != '1')
		move_player(game, new_x, new_y);
	return (0);
}
