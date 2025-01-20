/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:21:54 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/14 14:55:20 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_philo_death(t_program *data)
{
	pthread_mutex_lock(&data->is_dead_mutex);
	if (data->is_dead == 1)
	{
		pthread_mutex_unlock(&data->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->is_dead_mutex);
	return (0);
}

void	print(t_program *data, int philo, int state)
{
	if (state == FORK && check_philo_death(data) == 0)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d has taken a fork \U0001F374\033[0m\n",
			CYAN, get_timestamp(data), philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == EAT && check_philo_death(data) == 0)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is eating \U0001F35D\033[0m\n",
			YELLOW, get_timestamp(data), philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == SLEEP && check_philo_death(data) == 0)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is sleeping \U0001F4A4\033[0m\n",
			BLUE, get_timestamp(data), philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
}

void	print_bis(t_program *data, int philo, int state)
{
	if (state == THINK && check_philo_death(data) == 0)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is thinking \U0001F4AD\033[0m\n",
			WHITE, get_timestamp(data), philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == DEAD)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d died \U0001F480\033[0m\n",
			RED, get_timestamp(data), philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == END && check_philo_death(data) == 0)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%sEveryone ate ! \U00002705\033[0m\n", GREEN);
		pthread_mutex_unlock(&data->print_mutex);
	}
}
