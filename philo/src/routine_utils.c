/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:10:46 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/12 13:30:06 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	death_watch(t_philo *philo)
{
	long int	current_time;

	current_time = get_timestamp(philo->data);
	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	if (current_time > (philo->last_meal + philo->data->time_to_die))
	{
		pthread_mutex_lock(&philo->data->is_dead_mutex);
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%s%ldms %d died \U0001F480\033[0m\n", RED,
			get_timestamp(philo->data), philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
		// print_bis(philo->data, get_timestamp(philo->data), philo->id, DEAD);
		return (1);
	}
	return (0);
}

void	mortal_sleep_guardian(t_philo *philo)
{
	long int	sleep_start;

	sleep_start = get_time();
	while ((get_time() - sleep_start) < (long int)philo->data->time_to_sleep)
	{
		if (death_watch(philo) == 1)
			break ;
		usleep(500);
	}
}

void	mortal_eat_guardian(t_philo *philo)
{
	long int	eat_start;

	eat_start = get_time();
	while ((get_time() - eat_start) < (long int)philo->data->time_to_eat)
	{
		if (death_watch(philo) == 1)
			break ;
		usleep(500);
	}
}
