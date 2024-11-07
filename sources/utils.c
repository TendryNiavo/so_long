/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:09:57 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 16:12:16 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_char(char c, char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	is_correct_items(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0' || c == '\n')
		return (1);
	return (0);
}

void	check_items(char *str, t_data *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			game->count_p++;
		else if (str[i] == 'C')
			game->count_c++;
		else if (str[i] == 'E')
			game->count_e++;
		if (!is_correct_items(str[i]))
		{
			ft_error("Error\nInvalid content found\n");
			free_map(game);
			exit(1);
		}
		i++;
	}
}
