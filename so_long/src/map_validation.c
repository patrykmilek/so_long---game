/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:17:39 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 18:26:53 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_elements(t_game *game, int *player,
		int *collectibles, int *exit_count)
{
	int	i;
	int	j;

	i = 0;
	*player = 0;
	*collectibles = 0;
	*exit_count = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
				(*player)++;
			else if (game->map[i][j] == 'C')
				(*collectibles)++;
			else if (game->map[i][j] == 'E')
				(*exit_count)++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (*player == 1 && *collectibles >= 1 && *exit_count == 1);
}

static void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	validate_path(t_game *game)
{
	char				**map_copy;
	int					i;
	t_flood_fill_data	data;

	map_copy = allocate_map(game->map_height);
	if (!map_copy)
		return (0);
	i = 0;
	while (i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy, i);
			return (0);
		}
		i++;
	}
	data.collectibles = game->collectibles;
	data.exit_count = 0;
	data.game = game;
	flood_fill(map_copy, game->player_x, game->player_y, &data);
	free_map(map_copy, game->map_height);
	return (data.collectibles == 0 && data.exit_count > 0);
}

static void	handle_error(const char *message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

void	validate_map(char *map_path, t_game *game)
{
	int	player;
	int	collectibles;
	int	exit_count;

	game->map = read_map(map_path, &game->map_width, &game->map_height);
	if (!game->map)
		handle_error("Error\nFailed to read map\n");
	if (!check_walls(game) || !check_rectangle(game)
		|| !check_elements(game, &player, &collectibles, &exit_count))
		handle_error("Error\nInvalid map\n");
	find_player(game);
	if (game->player_x == -1 || game->player_y == -1)
		handle_error("Error\nPlayer position not found\n");
	game->collectibles = collectibles;
	game->initial_collectibles = collectibles;
	game->exit_count = exit_count;
	if (!validate_path(game))
		handle_error("Error\nNo valid path in the map\n");
}
