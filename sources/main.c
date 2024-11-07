/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:03:53 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 14:34:50 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_arguments(int argc, char **argv)
{
	char	*buff;

	if (argc != 2)
	{
		ft_error("Error\nThis program takes 1 argument\n");
		return (0);
	}
	buff = ft_strdup(argv[1]);
	if (!ft_strchr(buff, ".ber"))
	{
		ft_error("Error\nThe program only accepts a .ber file\n");
		free(buff);
		return (0);
	}
	free(buff);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	game;

	(void)argc;
	if (!check_arguments(argc, argv))
		return (1);
	init_game(&game, argv);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_handler, &game);
	mlx_hook(game.mlx_win, 33, (1L << 17), exit_game, &game);
	mlx_loop(game.mlx_ptr);
	free_map(&game);
	clean_game(&game);
	return (0);
}
