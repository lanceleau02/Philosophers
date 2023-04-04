/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:33:12 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/04 15:21:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>

# define FALSE -1
# define CYAN "\x1B[36m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define WHITE "\x1B[37m"
# define RED "\x1B[31m"

typedef enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD,
}	t_state;

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		nb_meals;
	unsigned int		last_meal;
	unsigned int		is_dead;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_program	*data;
}	t_philo;

typedef struct s_program
{
	long int		start_time;
	unsigned int	nb_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	nb_eat;
	unsigned int	full_meals;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}	t_program;

int			parsing(int argc, char **argv);
int			ft_atoi(const char *nptr);
long int	get_timestamp(t_program *data);
long int	get_time(void);
void		print_status(t_program *data, long int timestamp, int philo, int state);
void		philosophers(t_program *data);
void		*routine(void *philo);

#endif
