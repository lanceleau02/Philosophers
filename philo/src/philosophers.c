/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:13:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/12 15:27:40 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philosophers(t_program *data)
{
	if (init_philos(data) == 1 || init_mutexes(data) == 1
		|| init_threads(data) == 1)
		return (1);
	if (data->full_meals == data->nb_philo && data->is_dead != 1)
		print_bis(data, 0, 0, END);
	destroy_mutexes(data);
	return (0);
}
