/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_segments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:08:10 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/30 03:36:32 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_door_segment(t_door *new_door, t_data *data, t_vec2 pos1,
		t_vec2 pos2)
{
	new_door->id_seg[new_door->nb_seg] = add_segment(data, pos1, pos2, D);
	new_door->nb_seg++;
}

void	check_doors_segments(t_door *new_door, t_data *data, int x, int y)
{
	int		x2;
	int		y2;

	x2 = x + 1;
	y2 = y + 1;
	if (x > 0 && data->map.plan[y][x - 1] != '1')
		add_door_segment(new_door, data, (t_vec2){x, y}, (t_vec2){x, y2});
	if (x < (int)ft_strlen(data->map.plan[y]) - 1
		&& data->map.plan[y][x + 1] != '1')
		add_door_segment(new_door, data, (t_vec2){x2, y2}, (t_vec2){x2, y});
	if (y > 0 && x < (int)ft_strlen(data->map.plan[y - 1]) - 1
		&& data->map.plan[y - 1][x] != '1')
		add_door_segment(new_door, data, (t_vec2){x2, y}, (t_vec2){x, y});
	if (y < (int)array_len(data->map.plan) - 1
		&& x < (int)ft_strlen(data->map.plan[y + 1]) - 1
		&& data->map.plan[y + 1][x] != '1')
		add_door_segment(new_door, data, (t_vec2){x, y2}, (t_vec2){x2, y2});
}

void	check_door(t_data *data, int x, int y)
{
	int		i;
	t_door	*new_doors;

	new_doors = malloc(sizeof(t_door) * (data->nb_door + 1));
	i = 0;
	while (data->doors && i < data->nb_door)
	{
		new_doors[i] = data->doors[i];
		i++;
	}
	new_doors[i].nb_seg = 0;
	new_doors[i].pos = (t_vec2){x, y};
	check_doors_segments(&new_doors[i], data, x, y);
	data->nb_door++;
	free(data->doors);
	data->doors = new_doors;
}

void	find_doors(t_data *data, char **map)
{
	int	x;
	int	y;

	data->nb_door = 0;
	data->doors = NULL;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'D')
				check_door(data, x, y);
			x++;
		}
		y++;
	}
}
