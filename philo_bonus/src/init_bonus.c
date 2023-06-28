/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:19:33 by njegat            #+#    #+#             */
/*   Updated: 2023/06/13 18:46:45 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoll(argv[2]);
	data->t_eat = ft_atoll(argv[3]);
	data->t_sleep = ft_atoll(argv[4]);
	data->dead = FALSE;
	if (argc == 6)
		data->nb_must_eat = ft_atoi(argv[5]);
	else
		data->nb_must_eat = -1;
	sem_unlink("sem_write");
	sem_unlink("sem_end");
	sem_unlink("sem_forks");
	sem_unlink("sem_eat");
	data->sem_write = sem_open("sem_write", O_CREAT, S_IRWXU, 1);
	data->sem_end = sem_open("sem_end", O_CREAT, S_IRWXU, 0);
	data->forks = sem_open("sem_forks", O_CREAT, S_IRWXU, data->nb_philo);
	data->sem_eat = sem_open("sem_eat", O_CREAT, S_IRWXU, data->nb_philo);
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;
	char	*name;

	philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].nb_ate = 0;
		philo[i].tid = -1;
		name = ft_itoa(philo[i].id);
		sem_unlink(name);
		philo[i].sem_time = sem_open(name, O_CREAT, S_IRWXU, 1);
		free(name);
		sem_wait(data->sem_eat);
		i++;
	}
	return (philo);
}
