/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:25:06 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 19:04:07 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	**read_map(char *map_path, int *width, int *height);
int		process_map_lines(char **map, int *width, int fd);
char	**resize_map(char **map, int old_size, int new_size);
char	**allocate_map(int lines);
void	free_map(char **map, int lines);
char	*ft_itoa(int n);
int		num_len(int n);

#endif
