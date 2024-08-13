/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:32:17 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 19:01:01 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

void	start_game(char *map_path)
{
	t_game	game;

	validate_map(map_path, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_width * 96,
			game.map_height * 96, "so_long");
	game.moves = 0;
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_input, &game);
	mlx_loop(game.mlx);
}
