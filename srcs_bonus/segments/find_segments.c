/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_segments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:55:26 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/30 19:26:07 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_segment(t_data *data, t_vec2 vec1, t_vec2 vec2, enum e_card dir)
{
	t_segment	*new_segs;
	int			i;

	i = 0;
	new_segs = malloc(sizeof(t_segment) * (data->nb_seg + 1));
	while (data->segments && i < data->nb_seg)
	{
		new_segs[i] = data->segments[i];
		i++;
	}
	new_segs[i] = init_segment(vec1, vec2, dir);
	new_segs[i].id = i;
	free(data->segments);
	data->nb_seg++;
	data->segments = new_segs;
	return (data->segments[i].id);
}

void	check_there_is_seg(t_data *data, char **map, int x, int y)
{
	int	x2;
	int	y2;

	x2 = x + 1;
	y2 = y + 1;
	if (map[y][x] == '1' && x > 0 && map[y][x - 1] != '1'
		&& map[y][x - 1] != ' ')
		add_segment(data, (t_vec2){x, y}, (t_vec2){x, y2}, W);
	if (map[y][x] == '1' && x < (int)ft_strlen(map[y]) - 1
		&& map[y][x + 1] != '1' && map[y][x + 1] != ' ')
		add_segment(data, (t_vec2){x2, y2}, (t_vec2){x2, y}, E);
	if (map[y][x] == '1' && y > 0 && x < (int)ft_strlen(map[y - 1]) - 1
		&& map[y - 1][x] != '1' && map[y - 1][x] != ' ')
		add_segment(data, (t_vec2){x2, y}, (t_vec2){x, y}, N);
	if (map[y][x] == '1' && y < (int)array_len(map) - 1
		&& x < (int)ft_strlen(map[y + 1]) - 1 && map[y + 1][x] != '1'
		&& map[y + 1][x] != ' ')
		add_segment(data, (t_vec2){x, y2}, (t_vec2){x2, y2}, S);
}

void	find_segments(t_data *data, char **map)
{
	int	x;
	int	y;

	data->nb_seg = 0;
	data->segments = NULL;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			check_there_is_seg(data, map, x, y);
			x++;
		}
		y++;
	}
}
