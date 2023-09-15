/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:23:32 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/30 03:15:27 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	animate_doors(t_segment *segments, int nb_seg)
{
	int	i;

	i = 0;
	while (i < nb_seg)
	{
		if (segments[i].dir != D)
		{
			i++;
			continue ;
		}
		if ((segments[i].limit <= 0.0001 && segments[i].limit_incr < 0)
			|| (segments[i].limit >= 1.0 && segments[i].limit_incr > 0))
			segments[i].limit_incr = 0;
		if (segments[i].limit <= 0.0001)
			segments[i].limit = 0;
		if (segments[i].limit >= 1.0)
			segments[i].limit = 1.0;
		segments[i].limit += segments[i].limit_incr;
		i++;
	}
}

t_inter	intersect_door_seg(const t_segment *segment, const t_ray *ray)
{
	t_vec2	v1;
	t_vec2	v2;
	t_vec2	v3;
	t_inter	res;
	double	subpart;

	res.dist = -1.0;
	res.img_x = -1.0;
	res.dir = -1;
	if (0 <= dot_product(&segment->normal, &ray->dir))
		return (res);
	v2 = substract_vec(&segment->p2, &segment->p1);
	v3 = (t_vec2){-ray->dir.y, ray->dir.x};
	subpart = dot_product(&v2, &v3);
	if (subpart == 0.0)
		return (res);
	v1 = substract_vec(&ray->pos, &segment->p1);
	res.img_x = dot_product(&v1, &v3) / subpart;
	if (res.img_x < 0 || res.img_x > 1)
		return (res);
	res.dist = cross_product(&v2, &v1) / subpart;
	if (res.dist < 0)
		return (res);
	res.dir = segment->dir;
	return (res);
}

t_inter	intersect_door(const t_segment *segments, int nb_seg, const t_ray *ray)
{
	int		i;
	int		dist_to_player;
	t_inter	inter;
	t_inter	inter_test;

	i = -1;
	init_inter(&inter);
	dist_to_player = -1;
	while (++i < nb_seg)
	{
		if (dist_to_player != -1 && dist_to_player == segments[i].dist)
			return (inter);
		inter_test = intersect_door_seg(&segments[i], ray);
		if (inter_test.dist >= 0 && inter_test.img_x >= 0
			&& inter_test.img_x <= 1)
		{
			dist_to_player = segments[i].dist;
			if (inter.dist == -1 || inter_test.dist < inter.dist)
			{
				inter = inter_test;
				inter.seg_nb = i;
			}
		}
	}
	return (inter);
}

void	mod_door_segments(t_door *door, t_segment *segments, int nb_seg)
{
	int	i;
	int	j;

	i = 0;
	while (i < door->nb_seg)
	{
		j = 0;
		while (j < nb_seg)
		{
			if (segments[j].id != door->id_seg[i])
			{
				j++;
				continue ;
			}
			if (segments[j].limit == 0 || segments[j].limit_incr == -0.05)
				segments[j].limit_incr = 0.05;
			else if (segments[j].limit == 1.0 || segments[j].limit_incr == 0.05)
				segments[j].limit_incr = -0.05;
			j++;
		}
		i++;
	}
}

void	interact(t_segment *segments, int nb_seg, t_player player, t_data *data)
{
	t_ray	ray;
	t_inter	inter;
	int		i;
	int		j;

	ray.pos = player.pos;
	ray.rad = player.dir * PI_DIV_180;
	ray.dir.x = cos(ray.rad);
	ray.dir.y = sin(ray.rad);
	inter = intersect_door(segments, nb_seg, &ray);
	if (segments[inter.seg_nb].dir != D)
		return ;
	i = 0;
	while (i < data->nb_door)
	{
		j = 0;
		while (j < data->doors[i].nb_seg
			&& data->doors[i].id_seg[j] != segments[inter.seg_nb].id)
			j++;
		if (j < data->doors[i].nb_seg
			&& data->doors[i].id_seg[j] == segments[inter.seg_nb].id)
			break ;
		i++;
	}
	mod_door_segments(&data->doors[i], segments, nb_seg);
}
