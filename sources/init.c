/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:46:54 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/23 08:39:03 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player_position(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
			}
			else if (game->map[i][j] == 'E')
			{
				game->exit_y = i;
				game->exit_x = j;
			}
			j++;
		}
		i++;
	}
}

static void	init_count(t_data *game)
{
	game->count_c = 0;
	game->count_p = 0;
	game->count_e = 0;
}

void	init_game(t_data *game, char **argv)
{
	map_size(game, argv);
	if (game->map_height == 0)
	{
		ft_error("Error\nEmpty file\n");
		exit(1);
	}
	game->move = 0;
	game->map = malloc((sizeof (char *) * game->map_height));
	game->map[0] = NULL;
	extract_map(argv, game);
	if (!line_check(game))
		quit_game(game);
	init_count(game);
	scan_map(game);
	init_player_position(game);
	if (!check_map_error(game))
		quit_game(game);
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, (64 * game->map_width),
			(64 * game->map_height), "so_long");
	set_image(game);
	render_map(game);
}
