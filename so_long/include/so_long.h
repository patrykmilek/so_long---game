/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:24:55 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 18:44:54 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "utils.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	int		initial_collectibles;
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exit_count;
	int		moves;
}	t_game;

typedef struct s_flood_fill_data
{
	int		collectibles;
	int		exit_count;
	t_game	*game;
}	t_flood_fill_data;

void	validate_map(char *map_path, t_game *game);
void	start_game(char *map_path);
void	render_map(t_game *game);
int		handle_input(int key, t_game *game);
int		validate_path(t_game *game);
void	free_game(t_game *game);
char	**read_map(char *map_path, int *width, int *height);
int		check_walls(t_game *game);
int		validate_path(t_game *game);
void	flood_fill(char **map, int x, int y, t_flood_fill_data *data);
int		check_rectangle(t_game *game);
int		check_walls(t_game *game);
void	display_move_count(int moves);

#endif
