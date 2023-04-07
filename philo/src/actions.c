/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:32:52 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/07 16:01:29 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	is_eating(t_philo *philo)
{
	fork_pickup(philo);
	print(philo->data, get_timestamp(philo->data), philo->id, EAT);
	philo->nb_meals++;
	philo->last_meal = get_timestamp(philo->data);
	mortal_eat_guardian(philo);
	fork_putdown(philo);
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
