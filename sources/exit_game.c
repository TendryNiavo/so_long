/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:28:50 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/23 08:38:41 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit_game(t_data *game)
{
	free_map(game);
	exit(1);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	free_map(t_data *game)
{
	int	i;

	i = 0;
	if (game->map != NULL)
	{
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
