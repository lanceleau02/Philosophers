/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:13:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/04 16:42:03 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_program *data, long timestamp, int philo, int state)
{
	pthread_mutex_init(&data->print_mutex, NULL);
	if (state == FORK)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d has taken a fork \U0001F374\033[0m\n", CYAN, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == EAT)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is eating \U0001F35D\033[0m\n", YELLOW, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == SLEEP)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is sleeping \U0001F4A4\033[0m\n", BLUE, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == THINK)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is thinking \U0001F4AD\033[0m\n", WHITE, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == DEAD)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d died \U0001F480\033[0m\n", RED, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
}

static void	init_philos(t_program *data)
{
	unsigned int	i;

	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_meals = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].is_dead = 0;
		data->philo[i].left_fork = NULL;
		data->philo[i].right_fork = NULL;
		data->philo[i].data = data;
		i++;
	}
}

static void	init_mutexes(t_program *data)
{
	unsigned int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].left_fork = &data->forks[i];
		if (data->nb_philo == 1)
			break ;
		data->philo[i].right_fork = &data->forks[i + 1 % data->nb_philo];
		i++;
	}
}

static void	init_threads(t_program *data)
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

void	philosophers(t_program *data)
{
	init_philos(data);
	init_mutexes(data);
	init_threads(data);
}
