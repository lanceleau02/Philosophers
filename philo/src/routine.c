/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:59:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/06 16:07:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	death_watch(t_philo *philo)
{
	long int	current_time;

	current_time = get_timestamp(philo->data);
	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return (1);
	}
	if (current_time > (philo->last_meal + philo->data->time_to_die))
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%s%ldms %d died \U0001F480\033[0m\n", RED, get_timestamp(philo->data), philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	return (0);
}

static void	fork_pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	death_watch(philo);
	print_status(philo->data, get_timestamp(philo->data), philo->id, FORK);
	if (philo->data->nb_philo != 1)
	{
		pthread_mutex_lock(philo->right_fork);
		death_watch(philo);
		print_status(philo->data, get_timestamp(philo->data), philo->id, FORK);
	}
}

static void	fork_putdown(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	if (philo->data->nb_philo != 1)
		pthread_mutex_unlock(philo->right_fork);
}

void	mortal_sleep_guardian(t_philo *philo)
{
	long int	sleep_start_time;
	
	sleep_start_time = get_time();
	while ((get_time() - sleep_start_time) < (long int)philo->data->time_to_sleep
		&& philo->data->is_dead == 0)
		usleep(100);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->data->nb_philo == 1)
	{
		print_status(philo->data, get_timestamp(philo->data), philo->id, FORK);
		usleep(philo->data->time_to_die * 1000);
		print_status(philo->data, get_timestamp(philo->data), philo->id, DEAD);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(&philo->data->full_meals_mutex);
		if (death_watch(philo) == 1)
			break ;
		if (philo->nb_meals == (unsigned int)philo->data->nb_eat)
		{
			philo->data->full_meals++;
			break ;
		}
		pthread_mutex_unlock(&philo->data->full_meals_mutex);
		fork_pickup(philo);
		print_status(philo->data, get_timestamp(philo->data), philo->id, EAT);
		philo->nb_meals++;
		philo->last_meal = get_timestamp(philo->data);
		usleep(philo->data->time_to_eat * 1000);
		fork_putdown(philo);
		if (death_watch(philo) == 1)
			break ;
		print_status(philo->data, get_timestamp(philo->data), philo->id, SLEEP);
		mortal_sleep_guardian(philo);
		//if (death_watch(philo) == 1) // enlever si pas nescessaire
		//	break ;
		print_status(philo->data, get_timestamp(philo->data), philo->id, THINK);
	}
	pthread_mutex_unlock(&philo->data->full_meals_mutex);
	return (NULL);
}
