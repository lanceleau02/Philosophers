/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:14:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/10 18:37:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_program *data)
{
	unsigned int	i;

	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_meals = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].left_fork = NULL;
		data->philo[i].right_fork = NULL;
		data->philo[i].nb_forks = 0;
		data->philo[i].data = data;
		i++;
	}
}

void	init_mutexes(t_program *data)
{
	unsigned int	i;

	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->full_meals_mutex, NULL);
	pthread_mutex_init(&data->is_dead_mutex, NULL);
	data->forks = malloc(sizeof(t_forks) * data->nb_philo);
	i = 0;
	while (i < data->nb_philo)
	{
		data->forks[i].status = 0;
		pthread_mutex_init(&data->forks[i].fork_mutex, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].left_fork = &data->forks[i];
		if (data->nb_philo == 1)
			break ;
		data->philo[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		i++;
	}
}

void	init_threads(t_program *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}
