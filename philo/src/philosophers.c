/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:13:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/05 16:09:11 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_program *data, long timestamp, int philo, int state)
{
	pthread_mutex_lock(&data->is_dead_mutex);
	if (data->is_dead == 1)
	{
		pthread_mutex_unlock(&data->is_dead_mutex);
		return ;
	}
	pthread_mutex_unlock(&data->is_dead_mutex);
	if (state == FORK)
	{
		pthread_mutex_lock(&data->print_mutex);
		if (data->is_dead == 1)
		{
			pthread_mutex_unlock(&data->is_dead_mutex);
			pthread_mutex_unlock(&data->print_mutex);
			return ;
		}
		printf("%s%ldms %d has taken a fork \U0001F374\033[0m\n", CYAN, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == EAT)
	{
		pthread_mutex_lock(&data->print_mutex);
		pthread_mutex_lock(&data->is_dead_mutex);
		if (data->is_dead == 1)
		{
			pthread_mutex_unlock(&data->is_dead_mutex);
			pthread_mutex_unlock(&data->print_mutex);
			return ;
		}
		pthread_mutex_unlock(&data->is_dead_mutex);
		printf("%s%ldms %d is eating \U0001F35D\033[0m\n", YELLOW, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == SLEEP)
	{
		pthread_mutex_lock(&data->print_mutex);
		if (data->is_dead == 1)
		{
			pthread_mutex_unlock(&data->is_dead_mutex);
			pthread_mutex_unlock(&data->print_mutex);
			return ;
		}
		printf("%s%ldms %d is sleeping \U0001F4A4\033[0m\n", BLUE, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == THINK)
	{
		pthread_mutex_lock(&data->print_mutex);
		if (data->is_dead == 1)
		{
			pthread_mutex_unlock(&data->is_dead_mutex);
			pthread_mutex_unlock(&data->print_mutex);
			return ;
		}
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

void	philosophers(t_program *data)
{
	init_philos(data);
	init_mutexes(data);
	init_threads(data);
}
