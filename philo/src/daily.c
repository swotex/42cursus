/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:37:39 by njegat            #+#    #+#             */
/*   Updated: 2023/06/13 14:32:22 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_sleep(t_philo *philo)
{
	long long	time;
	long long	time2;

	time = get_current_time();
	time2 = get_current_time();
	print_term(philo, SLEEP);
	while (time_diff(time2, time) < philo->data->t_sleep)
	{
		if (is_dead(philo) == TRUE)
		{
			print_term(philo, DEAD);
			break ;
		}
		usleep(50);
		time = get_current_time();
	}
}

void	start_eat(t_philo *philo)
{
	long long	time;

	philo->start_time = get_current_time();
	time = get_current_time();
	print_term(philo, EAT);
	while (time_diff(philo->start_time, time) < philo->data->t_eat)
	{
		if (is_dead(philo) == TRUE)
		{
			print_term(philo, DEAD);
			break ;
		}
		usleep(50);
		time = get_current_time();
	}
	pthread_mutex_lock(&philo->data->mutex_meal);
	philo->nb_ate++;
	pthread_mutex_unlock(&philo->data->mutex_meal);
	pthread_mutex_lock(&philo->fork->mutex_fork);
	philo->fork->available = TRUE;
	pthread_mutex_unlock(&philo->fork->mutex_fork);
	pthread_mutex_lock(&philo->fork_n->mutex_fork);
	philo->fork_n->available = TRUE;
	pthread_mutex_unlock(&philo->fork_n->mutex_fork);
}

void	take_forkx(t_philo *philo, t_forks *forkx)
{
	while (is_dead(philo) == FALSE)
	{
		usleep(100);
		pthread_mutex_lock(&forkx->mutex_fork);
		if (forkx->available == TRUE)
		{
			forkx->available = FALSE;
			pthread_mutex_unlock(&forkx->mutex_fork);
			print_term(philo, FORK);
			break ;
		}
		pthread_mutex_unlock(&forkx->mutex_fork);
	}
}

void	take_forks(t_philo *philo)
{
	take_forkx(philo, philo->fork);
	if (is_dead(philo) == TRUE)
		print_term(philo, DEAD);
	take_forkx(philo, philo->fork_n);
	if (is_dead(philo) == TRUE)
		print_term(philo, DEAD);
}

void	*start_daily(void *vphilo)
{
	t_philo	*philo;

	philo = vphilo;
	philo->start_time = get_current_time();
	if (philo->id % 2 == 0)
		usleep(30000);
	if (philo->data->nb_philo == 1)
		philo_alone(philo);
	while (get_dead(philo->data) == FALSE)
	{
		if (get_dead(philo->data) == FALSE && is_end_meal(philo->data) == FALSE)
			take_forks(philo);
		if (get_dead(philo->data) == FALSE && is_end_meal(philo->data) == FALSE)
			start_eat(philo);
		if (is_end_meal(philo->data) == TRUE)
			break ;
		if (get_dead(philo->data) == FALSE && is_end_meal(philo->data) == FALSE)
			start_sleep(philo);
		if (get_dead(philo->data) == FALSE && is_end_meal(philo->data) == FALSE)
			print_term(philo, THINK);
		usleep(10);
	}
	return (NULL);
}
