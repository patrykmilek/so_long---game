/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:06:05 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 18:59:36 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/utils.h"

char	**resize_map(char **map, int old_size, int new_size)
{
	char	**new_map;
	int		j;

	new_map = allocate_map(new_size);
	if (!new_map)
	{
		free_map(map, old_size);
		return (NULL);
	}
	j = 0;
	while (j < old_size)
	{
		new_map[j] = map[j];
		j++;
	}
	free(map);
	return (new_map);
}

char	*read_and_trim_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

int	process_map_lines(char **map, int *width, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = read_and_trim_line(fd);
	while (line)
	{
		if (line[0] != '\0')
		{
			if (i == 0)
				*width = ft_strlen(line);
			map[i] = line;
			i++;
		}
		else
			free(line);
		line = read_and_trim_line(fd);
	}
	return (i);
}

void	display_move_count(int moves)
{
	char	*move_str;

	move_str = ft_itoa(moves);
	write(1, "Move count: ", 12);
	write(1, move_str, ft_strlen(move_str));
	write(1, "\n", 1);
	free(move_str);
}
