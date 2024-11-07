/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:51:54 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 14:28:34 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map_dup(char **map_dup, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_dup[i]);
		i++;
	}
	free(map_dup);
}

void	fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height - 1)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'P')
		return ;
	if (map[y][x] == 'E')
		return ;
	map[y][x] = 'P';
	if (y + 1 < data->map_height - 1)
		fill(map, x, y + 1, data);
	if (y > 0)
		fill(map, x, y - 1, data);
	if (x + 1 < data->map_width)
		fill(map, x + 1, y, data);
	if (x > 0)
		fill(map, x - 1, y, data);
}

void	flood_fill(char **map, t_data *data)
{
	fill(map, data->x, data->y + 1, data);
	fill(map, data->x, data->y - 1, data);
	fill(map, data->x + 1, data->y, data);
	fill(map, data->x - 1, data->y, data);
}

int	check_map_accessibility(t_data *data)
{
	char	**map_dup;
	int		i;
	int		count_collect;

	count_collect = 0;
	i = 0;
	map_dup = copy_map(data->map, data->map_height);
	if (!map_dup)
		return (0);
	flood_fill(map_dup, data);
	i = 0;
	while (i < data->map_height - 1)
	{
		count_collect += count_char('C', map_dup[i]);
		i++;
	}
	if (!check_exit(map_dup, count_collect, data))
	{
		free_map_dup(map_dup, data->map_height);
		ft_error("Error\nNo valid path available for this map\n");
		return (0);
	}
	free_map_dup(map_dup, data->map_height);
	return (1);
}
