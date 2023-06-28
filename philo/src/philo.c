/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:22:28 by njegat            #+#    #+#             */
/*   Updated: 2023/05/23 16:30:31 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*meal_check(void *philos)
{
	t_philo	*philo;
	int		count;
	int		i;

	philo = philos;
	count = 0;
	while (count < philo->data->nb_philo && get_dead(philo->data) == FALSE)
	{
		usleep(500);
		count = 0;
		i = 0;
		while (i < philo->data->nb_philo)
		{
			pthread_mutex_lock(&philo->data->mutex_meal);
			if (philo[i].nb_ate >= philo->data->nb_must_eat)
				count++;
			i++;
			pthread_mutex_unlock(&philo->data->mutex_meal);
		}
	}
	pthread_mutex_lock(&philo->data->mutex_meal);
	philo->data->end_eat = TRUE;
	pthread_mutex_unlock(&philo->data->mutex_meal);
	return (NULL);
}

pthread_t	start_meal(t_data *data, t_philo *philo)
{
	int			i;
	pthread_t	tid;

	i = 0;
	tid = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].tid, NULL, start_daily, &philo[i]);
		i++;
	}
	if (data->nb_must_eat != -1)
		pthread_create(&tid, NULL, meal_check, philo);
	return (tid);
}

void	wait_philo(t_data *data, t_philo *philo, t_forks *fork)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&fork[i].mutex_fork);
		i++;
	}
	free(fork);
	free(philo);
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_destroy(&data->mutex_write);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_forks		*forks;
	t_philo		*philo;
	pthread_t	tid;

	if (parsing_handler(argc, argv))
		return (1);
	init_data(&data, argc, argv);
	forks = init_fork(&data);
	philo = init_philo(&data, forks);
	if (!philo)
	{
		printf("Error malloc\n");
		free(forks);
		return (12);
	}
	tid = start_meal(&data, philo);
	if (data.nb_must_eat != -1)
		pthread_join(tid, NULL);
	wait_philo(&data, philo, forks);
	return (0);
}
