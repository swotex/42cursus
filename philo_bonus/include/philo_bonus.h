/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:21:15 by njegat            #+#    #+#             */
/*   Updated: 2023/06/13 13:41:06 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
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

typedef struct s_data
{
	int			nb_philo;
	long long	t_die;
	long long	t_eat;
	long long	t_sleep;
	sem_t		*sem_end;
	int			dead;
	int			nb_must_eat;
	sem_t		*sem_eat;
	sem_t		*sem_write;
	sem_t		*forks;
}	t_data;

typedef struct s_philo
{
	int				id;
	t_data			*data;
	long long		start_time;
	int				nb_ate;
	sem_t			*sem_time;
	pid_t			tid;
}	t_philo;
//parsing
int				parsing_handler(int argc, char **argv);
//utils
int				ft_atoi(const char *nptr);
long long		ft_atoll(const char *nptr);
char			*ft_itoa(int n);
int				is_dead(t_philo *philo);
long long		get_current_time(void);
long long		time_diff(long long start_time, long long time);
void			print_term(t_philo	*philo, int say);
//init
void			init_data(t_data *data, int argc, char **argv);
t_philo			*init_philo(t_data *data);
//daily
void			start_daily(t_philo *philo);
void			death_handler(t_philo *philo);

#endif
