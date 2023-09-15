/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:38:09 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/30 03:36:26 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_doors(t_data *data, t_door *doors, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_door)
	{
		j = 0;
		while (j < data->nb_seg)
		{
			if (data->segments[j].id == doors[i].id_seg[0])
			{
				if (data->segments[j].limit >= 0.5)
					map[(int)doors[i].pos.y][(int)doors[i].pos.x] = 'd';
				else
					map[(int)doors[i].pos.y][(int)doors[i].pos.x] = 'D';
				break ;
			}
			j++;
		}
		i++;
	}
}

void	open_door(t_door *door, t_segment *segments, int nb_seg)
{
	int	i;
	int	j;

	i = 0;
	while (i < door->nb_seg)
	{
		j = 0;
		while (j < nb_seg)
		{
			if (door->id_seg[i] == segments[j].id)
			{
				segments[j].limit_incr = 0.05;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	unstuck_player(t_data *data, t_door *doors, t_player player)
{
	int	i;

	if (data->map.plan[(int)player.pos.y][(int)player.pos.x] != 'D')
		return ;
	i = 0;
	while (i < data->nb_door)
	{
		if ((int)doors[i].pos.x == (int)player.pos.x
			&& (int)doors[i].pos.y == (int)player.pos.y)
			open_door(&doors[i], data->segments, data->nb_seg);
		i++;
	}
}
