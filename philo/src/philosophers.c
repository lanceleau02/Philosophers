/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:13:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/07 16:01:55 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers(t_program *data)
{
	init_philos(data);
	init_mutexes(data);
	init_threads(data);
	if (data->full_meals == data->nb_philo && data->is_dead != 1)
		print_bis(data, 0, 0, END);
	destroy_mutexes(data);
}
