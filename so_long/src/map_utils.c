/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:17:39 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 16:16:05 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/utils.h"

int	count_lines(char *map_path)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

char	**allocate_map(int lines)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	map[lines] = NULL;
	return (map);
}

void	free_map(char **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**read_map(char *map_path, int *width, int *height)
{
	char	**map;
	int		lines;
	int		i;
	int		fd;

	lines = count_lines(map_path);
	if (lines <= 0)
		return (NULL);
	*height = lines;
	map = allocate_map(lines);
	if (!map)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		free_map(map, lines);
		return (NULL);
	}
	i = process_map_lines(map, width, fd);
	close(fd);
	if (i < lines)
		map = resize_map(map, lines, i);
	return (map);
}
