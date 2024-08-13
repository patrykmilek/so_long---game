/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:00:00 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 18:26:33 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_top_bottom_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[game->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_left_right_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][game->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	if (!check_top_bottom_walls(game))
		return (0);
	if (!check_left_right_walls(game))
		return (0);
	return (1);
}

int	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->map_width)
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(char **map, int x, int y, t_flood_fill_data *data)
{
	if (x < 0 || y < 0 || x >= data->game->map_width
		|| y >= data->game->map_height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		data->collectibles--;
	if (map[y][x] == 'E')
		data->exit_count++;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}
