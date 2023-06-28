/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:33:22 by njegat            #+#    #+#             */
/*   Updated: 2023/06/13 18:42:25 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*check_death(void *vphilo)
{
	t_philo	*philo;

	philo = vphilo;
	while (is_dead(philo) == FALSE)
		usleep(10000);
	print_term(philo, DEAD);
	return (NULL);
}

void	death_handler(t_philo *philo)
{
	pthread_t	death;

	pthread_create(&death, NULL, check_death, philo);
	pthread_detach(death);
}
