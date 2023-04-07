/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:21:54 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/07 15:58:41 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_program *data, long int timestamp, int philo, int state)
{
	if (death_watch(data->philo) == 1)
		return ;
	else if (state == FORK)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d has taken a fork \U0001F374\033[0m\n",
			CYAN, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == EAT)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is eating \U0001F35D\033[0m\n",
			YELLOW, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == SLEEP)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is sleeping \U0001F4A4\033[0m\n",
			BLUE, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
}

void	print_bis(t_program *data, long int timestamp, int philo, int state)
{
	if (death_watch(data->philo) == 1)
		return ;
	else if (state == THINK)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d is thinking \U0001F4AD\033[0m\n",
			WHITE, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == DEAD)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%s%ldms %d died \U0001F480\033[0m\n", RED, timestamp, philo);
		pthread_mutex_unlock(&data->print_mutex);
	}
	else if (state == END)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%sEveryone ate ! \U00002705\033[0m\n", GREEN);
		pthread_mutex_unlock(&data->print_mutex);
	}
}
