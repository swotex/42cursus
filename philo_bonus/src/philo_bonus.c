/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:21:36 by njegat            #+#    #+#             */
/*   Updated: 2023/06/13 13:43:14 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	start_meal(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		start_daily(&philos[i]);
		i++;
	}
}

void	*listen_eat(void	*vdata)
{
	t_data	*data;
	int		i;

	data = vdata;
	i = 0;
	while (i < data->nb_philo)
	{
		sem_wait(data->sem_eat);
		i++;
	}
	sem_post(data->sem_end);
	return (NULL);
}

void	kill_all(t_philo *philos, t_data *data)
{
	int		i;
	char	*name;

	i = 0;
	while (i < data->nb_philo)
	{
		kill(philos[i].tid, SIGKILL);
		name = ft_itoa(philos[i].id);
		sem_unlink(name);
		free(name);
		sem_close(philos[i].sem_time);
		i++;
	}
	free(philos);
	sem_unlink("sem_write");
	sem_unlink("sem_end");
	sem_unlink("sem_forks");
	sem_unlink("sem_eat");
	sem_close(data->sem_write);
	sem_close(data->sem_end);
	sem_close(data->forks);
	sem_close(data->sem_eat);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philos;
	pid_t		pid;
	pthread_t	tid;

	if (parsing_handler(argc, argv))
		return (1);
	init_data(&data, argc, argv);
	philos = init_philo(&data);
	if (!philos)
	{
		printf("Error malloc\n");
		return (12);
	}
	start_meal(philos, &data);
	pid = fork();
	if (pid == 0)
	{
		pthread_create(&tid, NULL, listen_eat, &data);
		pthread_detach(tid);
	}
	sem_wait(data.sem_end);
	kill(pid, SIGKILL);
	kill_all(philos, &data);
	return (0);
}
