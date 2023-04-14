/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:14:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/14 11:45:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philos(t_program *data)
{
	unsigned int	i;

	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (data->philo == NULL)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_meals = 0;
		data->philo[i].nb_forks = 0;
		data->philo[i].last_meal = data->start_time;
		data->philo[i].left_fork = NULL;
		data->philo[i].right_fork = NULL;
		data->philo[i].nb_forks = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	init_mutexes(t_program *data)
{
	unsigned int	i;

	data->forks = malloc(sizeof(t_forks) * data->nb_philo);
	if (data->forks == NULL)
		return (1);
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
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->full_meals_mutex, NULL);
	pthread_mutex_init(&data->is_dead_mutex, NULL);
	return (0);
}

int	init_threads(t_program *data)
{
	unsigned int	i;
	int				ret;

	i = 0;
	while (i < data->nb_philo)
	{
		ret = pthread_create(&data->philo[i].thread, NULL,
				&routine, &data->philo[i]);
		if (ret != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		ret = pthread_join(data->philo[i].thread, NULL);
		if (ret != 0)
			return (1);
		i++;
	}
	return (0);
}
