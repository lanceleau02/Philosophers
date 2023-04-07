/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:59:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/07 16:02:24 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->data->nb_philo == 1)
	{
		print(philo->data, get_timestamp(philo->data), philo->id, FORK);
		usleep(philo->data->time_to_die * 1000);
		print_bis(philo->data, get_timestamp(philo->data), philo->id, DEAD);
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
			pthread_mutex_lock(&philo->data->full_meals_mutex);
			philo->data->full_meals++;
			pthread_mutex_unlock(&philo->data->full_meals_mutex);
			break ;
		}
		is_eating(philo);
		if (death_watch(philo) == 1)
			break ;
		is_sleeping(philo);
		if (death_watch(philo) == 1)
			break ;
		is_thinking(philo);
	}
	return (NULL);
}
