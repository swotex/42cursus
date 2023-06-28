/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:58:20 by njegat            #+#    #+#             */
/*   Updated: 2023/05/22 14:24:04 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <sys/time.h>

int	is_dead(t_philo *philo)
{
	long long	time;

	time = get_current_time();
	if (time_diff(philo->start_time, time) >= philo->data->t_die)
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

	pthread_mutex_lock(&philo->data->mutex_write);
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
			pthread_mutex_lock(&philo->data->mutex_dead);
			time = get_current_time();
			printf(RED "%lld %d died\n" NC, time, philo->id);
			philo->data->dead = TRUE;
			pthread_mutex_unlock(&philo->data->mutex_dead);
		}
	}
	pthread_mutex_unlock(&philo->data->mutex_write);
}

long long	time_diff(long long start_time, long long time)
{
	return (time - start_time);
}

int	is_end_meal(t_data *data)
{
	int	end;

	end = FALSE;
	pthread_mutex_lock(&data->mutex_meal);
	if (data->nb_must_eat != -1)
		end = data->end_eat;
	pthread_mutex_unlock(&data->mutex_meal);
	return (end);
}
