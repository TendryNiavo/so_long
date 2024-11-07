/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:27:20 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/23 08:47:53 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_collectible(t_data *game)
{
	int	collect;
	int	i;

	i = 0;
	collect = 0;
	while (i < game->map_height)
	{
		collect += count_char('C', game->map[i]);
		i++;
	}
	game->count_c = collect;
	return (collect);
}

int	check_map_error(t_data *game)
{
	if (!check_walls(game))
	{
		ft_error("Error\nThe map must be surrounded by walls\n");
		return (0);
	}
	if (game->count_p != 1)
	{
		ft_error("Error\nThe number of players must be equal to 1\n");
		return (0);
	}
	if (game->count_c < 1)
	{
		ft_error("Error\nThe number of collectibles must be at least 1\n");
		return (0);
	}
	if (game->count_e != 1)
	{
		ft_error("Error\nThe number of exits must be equal to 1\n");
		return (0);
	}
	else if (!check_map_accessibility(game))
		return (0);
	return (1);
}
