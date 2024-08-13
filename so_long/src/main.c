/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilek <pmilek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:24:37 by pmilek            #+#    #+#             */
/*   Updated: 2024/08/13 15:53:37 by pmilek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 34);
		return (1);
	}
	start_game(argv[1]);
	return (0);
}
