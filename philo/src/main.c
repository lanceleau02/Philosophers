/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:27:44 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/03 15:47:06 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	struct_init(t_program *data, char **argv)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	data->start_time = tv.tv_sec;
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	if (argv[4] != NULL)
		data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->nb_eat = ft_atoi(argv[5]);
}

typedef struct s_test
{
	pthread_mutex_t	mutex;
	int				a;
}	t_test;

static void	*test1(void *oui)
{
	pthread_mutex_lock(&((t_test *)oui)->mutex);
	((t_test *)oui)->a += 1;
	printf("t1 = %d\n", ((t_test *)oui)->a);
	pthread_mutex_unlock(&((t_test *)oui)->mutex);	
	return (NULL);
}

static void	*test2(void *oui)
{
	pthread_mutex_lock(&((t_test *)oui)->mutex);
	((t_test *)oui)->a += 2;
	printf("t2 = %d\n", ((t_test *)oui)->a);
	pthread_mutex_unlock(&((t_test *)oui)->mutex);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_program		data;
	pthread_t		t1;
	pthread_t		t2;
	t_test			oui;

	if (parsing(argc, argv) == 1)
		return (1);
	struct_init(&data, argv);
	oui.a = 0;
	pthread_mutex_init(&oui.mutex, NULL);
	pthread_create(&t1, NULL, &test1, &oui);
	pthread_create(&t2, NULL, &test2, &oui);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&oui.mutex);
	//philosophers(&data);
	return (0);
}
