/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:27:44 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/11 13:49:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	struct_init(t_program *data, char **argv)
{
	data->start_time = get_time();
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	if (argv[4] != NULL)
		data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	data->full_meals = 0;
	data->is_dead = 0;
}

int	main(int argc, char **argv)
{
	t_program	data;

	if (parsing(argc, argv) == 1)
		return (1);
	struct_init(&data, argv);
	philosophers(&data);
	free(data.philo);
	free(data.forks);
	return (0);
}
