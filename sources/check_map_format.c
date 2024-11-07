/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:59:18 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 14:29:03 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_top_wall(char *str, t_data *game)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '1')
		i++;
	if (game->map_width == i)
		return (1);
	return (0);
}

int	check_walls(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (i == 0 || i == game->map_height)
		{
			if (!check_top_wall(game->map[i], game))
				return (0);
		}
		else
		{
			if (game->map[i][0] != '1'
				|| game->map[i][game->map_width - 1] != '1')
				return (0);
		}
		i++;
	}
	if (!check_top_wall(game->map[i - 1], game))
		return (0);
	return (1);
}

int	line_check(t_data *game)
{
	int	i;
	int	map_line;

	i = 0;
	while (i < game->map_height)
	{
		if (i != game->map_height - 1)
			map_line = (int)ft_strlen(game->map[i]) - 1;
		else
			map_line = (int)ft_strlen(game->map[i]);
		if (map_line != game->map_width)
		{
			ft_error("Error\nThe map must be rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}
