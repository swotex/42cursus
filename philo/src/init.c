/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:27:07 by njegat            #+#    #+#             */
/*   Updated: 2023/05/23 10:43:34 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_data(t_data *data, int argc, char **argv)
{
	pthread_mutex_init(&data->mutex_write, NULL);
	pthread_mutex_init(&data->mutex_dead, NULL);
	pthread_mutex_init(&data->mutex_meal, NULL);
	data->end_eat = FALSE;
	data->nb_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoll(argv[2]);
	data->t_eat = ft_atoll(argv[3]);
	data->t_sleep = ft_atoll(argv[4]);
	data->dead = FALSE;
	if (argc == 6)
		data->nb_must_eat = ft_atoi(argv[5]);
	else
		data->nb_must_eat = -1;
}

t_forks	*init_fork(t_data *data)
{
	t_forks	*fork;
	int		i;

	fork = malloc(data->nb_philo * sizeof(t_forks));
	if (!fork)
		return (NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&fork[i].mutex_fork, NULL);
		fork[i].available = TRUE;
		i++;
	}
	return (fork);
}

t_philo	*init_philo(t_data *data, t_forks *fork)
{
	t_philo	*philo;
	int		i;

	if (!fork)
		return (NULL);
	philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].data = data;
		philo[i].fork = &fork[i];
		philo[i].id = i + 1;
		philo[i].nb_ate = 0;
		if (i < data->nb_philo - 1)
			philo[i].fork_n = &fork[i + 1];
		else
			philo[i].fork_n = &fork[0];
		i++;
	}
	return (philo);
}
