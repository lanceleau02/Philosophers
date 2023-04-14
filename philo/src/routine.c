/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:59:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/14 14:58:14 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	single_philosopher_handler(t_philo *philo)
{
	print(philo->data, philo->id, FORK);
	usleep(philo->data->time_to_die * 1000);
	print_bis(philo->data, philo->id, DEAD);
}

static void	update_full_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->full_meals_mutex);
	philo->data->full_meals++;
	pthread_mutex_unlock(&philo->data->full_meals_mutex);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->data->nb_philo == 1)
	{
		single_philosopher_handler(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(20000);
	while (1)
	{
		if (death_watch(philo) == 1)
			break ;
		if (philo->nb_meals == philo->data->nb_eat)
		{
			update_full_meals(philo);
			break ;
		}
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}
