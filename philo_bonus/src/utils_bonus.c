/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:48:33 by njegat            #+#    #+#             */
/*   Updated: 2023/06/14 12:27:08 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <sys/time.h>

int	is_dead(t_philo *philo)
{
	long long	time;
	int			result;

	sem_wait(philo->sem_time);
	time = get_current_time();
	result = time_diff(philo->start_time, time);
	sem_post(philo->sem_time);
	if (result >= philo->data->t_die)
		return (TRUE);
	else
		return (FALSE);
}

long long	get_current_time(void)
{
	struct timeval	current_time;
	long long		time;

	gettimeofday(&current_time, NULL);
	time = (long long)current_time.tv_sec;
	time = (time * 1000) + (long long)(current_time.tv_usec / 1000);
	return (time);
}

void	print_term(t_philo	*philo, int say)
{
	long long	time;

	sem_wait(philo->data->sem_write);
	time = get_current_time();
	if (philo->data->dead == FALSE)
	{
		if (say == FORK)
			printf(YELLOW "%lld %d has taken a fork\n" NC, time, philo->id);
		else if (say == EAT)
			printf(GREEN "%lld %d is eating\n" NC, time, philo->id);
		else if (say == SLEEP)
			printf(BLUE "%lld %d  is sleeping\n" NC, time, philo->id);
		else if (say == THINK)
			printf(CYAN "%lld %d is thinking\n" NC, time, philo->id);
		else if (say == DEAD)
		{
			printf(RED "%lld %d died\n" NC, time, philo->id);
			sem_post(philo->data->sem_end);
			return ;
		}
	}
	sem_post(philo->data->sem_write);
}

long long	time_diff(long long start_time, long long time)
{
	return (time - start_time);
}
