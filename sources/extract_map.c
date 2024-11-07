/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:58:04 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 15:50:07 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	extract_map(char **str, t_data *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(str[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error\nMap not found\n");
		exit(0);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	close(fd);
}
