/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:53:19 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/12 15:02:56 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(int argc, char **argv)
{
	if (argc < 5)
		printf("Error\nToo few arguments.\n");
	else if (argc > 6)
		printf("Error\nToo many arguments.\n");
	else if (ft_atoi(argv[1]) == FALSE || ft_atoi(argv[1]) <= 0
		|| str_is_digit(argv[1]) == 1)
		printf("Error\nPlease enter a valid number of philosophers.\n");
	else if (ft_atoi(argv[2]) == FALSE || ft_atoi(argv[2]) <= 0
		|| str_is_digit(argv[2]) == 1)
		printf("Error\nPlease enter a valid time to die.\n");
	else if (ft_atoi(argv[3]) == FALSE || ft_atoi(argv[3]) <= 0
		|| str_is_digit(argv[3]) == 1)
		printf("Error\nPlease enter a valid time to eat.\n");
	else if (argv[4] != NULL && (ft_atoi(argv[4]) == FALSE
			|| ft_atoi(argv[4]) <= 0 || str_is_digit(argv[4]) == 1))
		printf("Error\nPlease enter a valid time to spleep.\n");
	else if (argv[5] != NULL && (ft_atoi(argv[5]) == FALSE
			|| ft_atoi(argv[5]) < 0 || str_is_digit(argv[5]) == 1))
		printf("Error\nPlease enter a valid number of times each philosopher \
must eat.\n");
	else
		return (0);
	return (1);
}
