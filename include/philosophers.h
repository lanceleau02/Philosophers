/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:33:12 by laprieur          #+#    #+#             */
/*   Updated: 2023/04/14 14:55:45 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FALSE -1
# define CYAN "\x1B[36m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define WHITE "\x1B[37m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"

struct	s_program;

typedef enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD,
	END,
}	t_state;

typedef struct s_forks
{
	unsigned int	status;
	pthread_mutex_t	fork_mutex;
}	t_forks;

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		nb_meals;
	unsigned int		nb_forks;
	long int			last_meal;
	pthread_t			thread;
	t_forks				*left_fork;
	t_forks				*right_fork;
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
	t_forks			*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	full_meals_mutex;
	pthread_mutex_t	is_dead_mutex;
}	t_program;

int			death_watch(t_philo *philo);
int			ft_atoi(const char *nptr);
int			init_mutexes(t_program *data);
int			init_philos(t_program *data);
int			init_threads(t_program *data);
int			parsing(int argc, char **argv);
int			philosophers(t_program *data);
int			str_is_digit(const char *str);
void		destroy_mutexes(t_program *data);
void		is_eating(t_philo *philo);
void		is_sleeping(t_philo *philo);
void		is_thinking(t_philo *philo);
void		mortal_sleep_guardian(t_philo *philo);
void		mortal_eat_guardian(t_philo *philo);
void		print(t_program *data, int philo, int state);
void		print_bis(t_program *data, int philo, int state);
void		*routine(void *philo);
long int	get_time(void);
long int	get_timestamp(t_program *data);

#endif
