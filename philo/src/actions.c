/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:32:52 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/12 09:39:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	forks_checker(t_philo *philo)
{
	while (philo->nb_forks != 2)
	{
		if (death_watch(philo) == 1)
			return ;
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		if (philo->left_fork->status == 0)
		{
			philo->left_fork->status = 1;
			philo->nb_forks++;
			print(philo->data, get_timestamp(philo->data), philo->id, FORK);
		}
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		if (philo->right_fork->status == 0)
		{
			philo->right_fork->status = 1;
			philo->nb_forks++;
			print(philo->data, get_timestamp(philo->data), philo->id, FORK);
		}
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	}
}

void	is_eating(t_philo *philo)
{
	forks_checker(philo);
	print(philo->data, get_timestamp(philo->data), philo->id, EAT);
	philo->nb_meals++;
	philo->last_meal = get_timestamp(philo->data);
	mortal_eat_guardian(philo);
	philo->nb_forks = 0;
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	philo->left_fork->status = 0;
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	philo->right_fork->status = 0;
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
}

void	is_sleeping(t_philo *philo)
{
	print(philo->data, get_timestamp(philo->data), philo->id, SLEEP);
	mortal_sleep_guardian(philo);
}

void	is_thinking(t_philo *philo)
{
	print_bis(philo->data, get_timestamp(philo->data), philo->id, THINK);
}
