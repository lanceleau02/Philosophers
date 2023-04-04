/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:59:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/04 11:29:55 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.c"

static void	fork_pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(get_timestamp, philo->id, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_status(get_timestamp, philo->id, FORK);
}

static void	fork_putdown(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	*routine(void *philo)
{
	if (philo->id % 2 == 0)
		uspleep(500);
	while (1)
	{
		fork_pickup(philo);
		print_status(get_timestamp, philo->id, EAT);
		usleep(philo->data->time_to_eat);
		fork_putdown(philo);
		print_status(get_timestamp, philo->id, SLEEP);
		usleep(philo->data->time_to_sleep);
		print_status(get_timestamp, philo->id, THINK);
	}
}
