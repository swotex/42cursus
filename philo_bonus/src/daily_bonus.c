/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:37:46 by njegat            #+#    #+#             */
/*   Updated: 2023/06/13 18:55:32 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_term(philo, FORK);
	sem_wait(philo->data->forks);
	print_term(philo, FORK);
}

void	start_eat(t_philo *philo)
{
	long long	time;

	sem_wait(philo->sem_time);
	philo->start_time = get_current_time();
	sem_post(philo->sem_time);
	time = get_current_time();
	print_term(philo, EAT);
	philo->nb_ate++;
	while (time_diff(philo->start_time, time) < philo->data->t_eat)
	{
		usleep(100);
		time = get_current_time();
	}
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	start_sleep(t_philo *philo)
{
	long long	time;
	long long	time2;

	time = get_current_time();
	time2 = get_current_time();
	print_term(philo, SLEEP);
	while (time_diff(time, time2) < philo->data->t_sleep)
	{
		usleep(100);
		time2 = get_current_time();
	}
}

void	start_daily(t_philo *philo)
{
	philo->tid = fork();
	if (philo->tid == 0)
	{
		philo->start_time = get_current_time();
		if (philo->id % 2)
			usleep(5000);
		if (philo->data->nb_philo == 1)
		{
			print_term(philo, FORK);
			usleep(philo->data->t_die * 1000);
			print_term(philo, DEAD);
		}
		death_handler(philo);
		while (1)
		{
			take_fork(philo);
			start_eat(philo);
			if (philo->nb_ate == philo->data->nb_must_eat)
				sem_post(philo->data->sem_eat);
			start_sleep(philo);
			print_term(philo, THINK);
			usleep(200);
		}
	}
}
