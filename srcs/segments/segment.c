/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:07:43 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/18 21:25:45 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	move_point(const t_vec2 *pos, const t_vec2 *vec, double dist)
{
	t_vec2	res;

	res.x = pos->x + (vec->x * dist);
	res.y = pos->y + (vec->y * dist);
	return (res);
}

t_vec2	normalize_vec(const t_vec2 *vec)
{
	t_vec2	res;
	double	length;

	length = sqrt((vec->x * vec->x) + (vec->y * vec->y));
	res.x = vec->x / length;
	res.y = vec->y / length;
	return (res);
}

double	get_dist(const t_vec2 *p1, const t_vec2 *p2)
{
	double	res;
	double	dx;
	double	dy;

	dx = pow(p2->x - p1->x, 2.0);
	dy = pow(p2->y - p1->y, 2.0);
	res = sqrt(dx + dy);
	return (res);
}

t_segment	init_segment(t_vec2 vec1, t_vec2 vec2, enum e_card dir)
{
	t_segment	seg;
	double		dx;
	double		dy;

	seg.p1 = vec1;
	seg.p2 = vec2;
	dx = vec2.x - vec1.x;
	dy = vec2.y - vec1.y;
	seg.normal = (t_vec2){-dy, dx};
	seg.normal = normalize_vec(&seg.normal);
	seg.dir = dir;
	return (seg);
}

void	sort_segments(const t_vec2 *pos, t_segment *segments, int nb_seg)
{
	int			i;
	double		dist;
	t_segment	tmp;

	i = 0;
	while (i < nb_seg)
	{
		segments[i].dist = get_dist(&segments[i].p1, pos);
		dist = get_dist(&segments[i].p2, pos);
		if (dist < segments[i].dist)
			segments[i].dist = dist;
		i++;
	}
	i = 0;
	while (++i < nb_seg)
	{
		if (segments[i].dist < segments[i - 1].dist)
		{
			tmp = segments[i];
			segments[i] = segments[i - 1];
			segments[i - 1] = tmp;
			i = 0;
		}
	}
}
