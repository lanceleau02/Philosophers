/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:33:12 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/07 16:00:04 by laprieur         ###   ########.fr       */
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
# define GREEN "\x1B[32m"

typedef enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD,
	END,
}	t_state;

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		nb_meals;
	unsigned int		last_meal;
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
	unsigned int	is_dead;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	full_meals_mutex;
	pthread_mutex_t	is_dead_mutex;
}	t_program;

int			death_watch(t_philo *philo);
int			ft_atoi(const char *nptr);
int			parsing(int argc, char **argv);
void		destroy_mutexes(t_program *data);
void		fork_pickup(t_philo *philo);
void		fork_putdown(t_philo *philo);
void		init_mutexes(t_program *data);
void		init_philos(t_program *data);
void		init_threads(t_program *data);
void		is_eating(t_philo *philo);
void		is_sleeping(t_philo *philo);
void		is_thinking(t_philo *philo);
void		mortal_sleep_guardian(t_philo *philo);
void		mortal_eat_guardian(t_philo *philo);
void		philosophers(t_program *data);
void		print(t_program *data, long int timestamp, int philo, int state);
void		print_bis(t_program *data, long int timestamp, int philo,
				int state);
void		*routine(void *philo);
long int	get_time(void);
long int	get_timestamp(t_program *data);

#endif
