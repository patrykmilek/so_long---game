/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:32:30 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 19:02:37 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx/mlx.h"
#include "../include/utils.h"

int	close_window(t_game *game);

static void	render_tile(t_game *game, int x, int y, char tile)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = NULL;
	if (tile == '1')
		img = mlx_xpm_file_to_image(game->mlx, "t/wall.xpm", &img_w, &img_h);
	else if (tile == '0')
		img = mlx_xpm_file_to_image(game->mlx, "t/road.xpm", &img_w, &img_h);
	else if (tile == 'C')
		img = mlx_xpm_file_to_image(game->mlx, "t/coll.xpm", &img_w, &img_h);
	else if (tile == 'P')
		img = mlx_xpm_file_to_image(game->mlx, "t/player.xpm", &img_w, &img_h);
	else if (tile == 'E')
		img = mlx_xpm_file_to_image(game->mlx, "t/exit.xpm", &img_w, &img_h);
	if (img)
	{
		mlx_put_image_to_window(game->mlx, game->win, img, x * 96, y * 96);
		mlx_destroy_image(game->mlx, img);
	}
	else
	{
		write(2, "Error\nFailed to load image\n", 27);
		exit(1);
	}
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->map_width
		|| new_y >= game->map_height)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles == 0)
			close_window(game);
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	display_move_count(game->moves);
	render_map(game);
}

int	handle_input(int key, t_game *game)
{
	if (key == 65307)
		close_window(game);
	else if (key == 119)
		move_player(game, game->player_x, game->player_y - 1);
	else if (key == 115)
		move_player(game, game->player_x, game->player_y + 1);
	else if (key == 97)
		move_player(game, game->player_x - 1, game->player_y);
	else if (key == 100)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

void	free_game(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	if (game->mlx && game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
}
