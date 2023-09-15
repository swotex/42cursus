/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 03:15:40 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/29 22:08:03 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_inter	intersect_seg(const t_segment *segment, const t_ray *ray)
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
	if (res.img_x < segment->limit || res.img_x > 1)
		return (res);
	res.dist = cross_product(&v2, &v1) / subpart;
	res.dir = segment->dir;
	res.img_x -= segment->limit;
	return (res);
}

void	init_inter(t_inter *inter)
{
	inter->dist = -1.0;
	inter->img_x = 0.0;
	inter->dir = 0;
	inter->seg_nb = 0;
}

t_inter	intersect_segs(const t_segment *segments, int nb_seg, const t_ray *ray)
{
	int		i;
	double	dist_to_player;
	t_inter	inter;
	t_inter	inter_test;

	i = 0;
	init_inter(&inter);
	dist_to_player = -1;
	while (i < nb_seg)
	{
		if (dist_to_player != -1 && segments[i].dist - dist_to_player >= 0.1)
			return (inter);
		inter_test = intersect_seg(&segments[i], ray);
		if (inter_test.dist >= 0 && inter_test.img_x >= 0
			&& inter_test.img_x <= 1)
		{
			dist_to_player = segments[i].dist;
			if (inter.dist == -1 || inter_test.dist < inter.dist)
				inter = inter_test;
		}
		i++;
	}
	return (inter);
}

void	raycasting(const t_segment *segments, int nb_seg, t_player player,
			t_data *data)
{
	const double	incr_dir = FOV / WIDTH;
	const double	start_dir = player.dir - (FOV / 2);
	t_inter			inter;
	int				i;
	t_ray			ray;

	i = 0;
	ray.pos = player.pos;
	while (i < WIDTH)
	{
		ray.rad = (start_dir + (i * incr_dir)) * PI_DIV_180;
		ray.dir.x = cos(ray.rad);
		ray.dir.y = sin(ray.rad);
		inter = intersect_segs(segments, nb_seg, &ray);
		i++;
		if (inter.dist == -1.0)
			continue ;
		draw_wall(&inter, i - 1, ray.rad - (player.dir * PI_DIV_180), data);
	}
}
