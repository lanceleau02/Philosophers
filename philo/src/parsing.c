/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:53:19 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/03 13:16:24 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(int argc, char **argv)
{
	if (argc < 5)
		printf("Error\nToo few arguments.\n");
	else if (argc > 6)
		printf("Error\nToo many arguments.\n");
	else if (ft_atoi(argv[1]) == FALSE)
		printf("Error\nPlease enter a valid number of philosophers.\n");
	else if (ft_atoi(argv[2]) == FALSE)
		printf("Error\nPlease enter a valid time to die.\n");
	else if (ft_atoi(argv[3]) == FALSE)
		printf("Error\nPlease enter a valid time to eat.\n");
	else if (argv[4] != NULL && ft_atoi(argv[4]) == FALSE)
		printf("Error\nPlease enter a valid time to spleep.\n");
	else if (argv[5] != NULL && ft_atoi(argv[5]) == FALSE)
		printf("Error\nPlease enter a valid number of times each philosopher \
			must eat.\n");
	else
		return (0);
	return (1);
}
