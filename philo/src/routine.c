/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:59:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/04 15:35:58 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	fork_pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo->data, get_timestamp(philo->data), philo->id, FORK);
	if (philo->data->nb_philo != 1)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo->data, get_timestamp(philo->data), philo->id, FORK);
	}
}

static void	fork_putdown(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	if (philo->data->nb_philo != 1)
		pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		usleep(500);
	while (philo->data->full_meals <= philo->data->nb_eat)
	{
		if (philo->nb_meals == philo->data->nb_eat)
		{
			philo->data->full_meals++;
			break ;
		}
		if (philo->data->nb_philo == 1)
		{
			fork_pickup(philo);
			print_status(philo->data, get_timestamp(philo->data), philo->id, DEAD);
			break ;
		}
		print_status(philo->data, get_timestamp(philo->data), philo->id, EAT);
		philo->nb_meals++;
		usleep(philo->data->time_to_eat);
		fork_putdown(philo);
		print_status(philo->data, get_timestamp(philo->data), philo->id, SLEEP);
		usleep(philo->data->time_to_sleep);
		print_status(philo->data, get_timestamp(philo->data), philo->id, THINK);
	}
	return (NULL);
}
