/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:07:34 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 15:51:05 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_size(t_data *game, char **str)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(str[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error\nMap not found\n");
		exit(0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map_width = ft_strlen(line);
		height++;
		free(line);
	}
	game->map_height = height;
	close(fd);
}

char	**copy_map(char **map, int height)
{
	char	**map_dup;
	int		i;

	i = 0;
	map_dup = malloc(sizeof(char *) * height);
	if (!map_dup)
		return (NULL);
	while (i < height)
	{
		map_dup[i] = strdup(map[i]);
		if (!map_dup[i])
		{
			while (i > 0)
			{
				free(map_dup[--i]);
			}
			free(map_dup);
			return (NULL);
		}
		i++;
	}
	return (map_dup);
}

void	scan_map(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		check_items(game->map[i], game);
		i++;
	}
}

int	check_exit(char **map, int collect_nb, t_data *game)
{
	int	y;
	int	x;

	y = game->exit_y;
	x = game->exit_x;
	if (collect_nb != 0)
		return (0);
	if (map[y][x + 1] == 'P')
		return (1);
	else if (map[y][x - 1] == 'P')
		return (1);
	else if (map[y + 1][x] == 'P')
		return (1);
	else if (map[y - 1][x] == 'P')
		return (1);
	return (0);
}
