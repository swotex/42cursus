/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:02:05 by njegat            #+#    #+#             */
/*   Updated: 2023/05/23 12:13:19 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define GREEN "\e[1;32m"
# define RED "\e[1;31m"
# define BLUE "\e[1;34m"
# define CYAN "\e[1;36m"
# define FALSE 0
# define TRUE 1
# define FORK 12
# define EAT 13
# define SLEEP 14
# define THINK 15
# define DEAD 16

typedef struct s_forks
{
	pthread_mutex_t	mutex_fork;
	int				available;
}	t_forks;

typedef struct s_data
{
	int				end_eat;
	pthread_mutex_t	mutex_meal;
	int				nb_philo;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	pthread_mutex_t	mutex_dead;
	int				dead;
	int				nb_must_eat;
	pthread_mutex_t	mutex_write;
}	t_data;

typedef struct s_philo
{
	int			id;
	t_data		*data;
	long long	start_time;
	int			nb_ate;
	t_forks		*fork;
	t_forks		*fork_n;
	pthread_t	tid;
}	t_philo;
//parsing
int				parsing_handler(int argc, char **argv);
//utils
int				ft_atoi(const char *nptr);
long long		ft_atoll(const char *nptr);
int				is_dead(t_philo *philo);
long long		get_current_time(void);
long long		time_diff(long long start_time, long long time);
void			print_term(t_philo	*philo, int say);
int				get_dead(t_data *data);
void			philo_alone(t_philo *philo);
//init
void			init_data(t_data *data, int argc, char **argv);
t_forks			*init_fork(t_data *data);
t_philo			*init_philo(t_data *data, t_forks *fork);
int				is_end_meal(t_data *data);
//daily
void			*start_daily(void *vphilo);
void			take_forks(t_philo *philo);
void			start_eat(t_philo *philo);
void			start_sleep(t_philo *philo);

#endif
