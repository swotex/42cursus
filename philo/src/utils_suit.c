/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_suit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:22:18 by njegat            #+#    #+#             */
/*   Updated: 2023/05/23 12:13:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	get_dead(t_data *data)
{
	int	dead;

	pthread_mutex_lock(&data->mutex_dead);
	dead = data->dead;
	pthread_mutex_unlock(&data->mutex_dead);
	return (dead);
}

void	philo_alone(t_philo *philo)
{
	print_term(philo, FORK);
	usleep(philo->data->t_die * 1000);
	print_term(philo, DEAD);
}
