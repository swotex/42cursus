/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 03:15:40 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/18 22:12:56 by tdhaussy         ###   ########.fr       */
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
	if (0 <= dot_product(&segment->normal, &ray->dir))
		return (res);
	v2 = substract_vec(&segment->p2, &segment->p1);
	v3 = (t_vec2){-ray->dir.y, ray->dir.x};
	subpart = dot_product(&v2, &v3);
	if (subpart == 0.0)
		return (res);
	v1 = substract_vec(&ray->pos, &segment->p1);
	res.dist = cross_product(&v2, &v1) / subpart;
	if (res.dist < 0)
		return (res);
	res.img_x = dot_product(&v1, &v3) / subpart;
	if (res.img_x < 0 || res.img_x > 1)
		return (res);
	res.dir = segment->dir;
	return (res);
}

t_inter	intersect_segs(const t_segment *segments, int nb_seg, const t_ray *ray)
{
	int		i;
	t_inter	inter;

	i = 0;
	inter.dist = -1.0;
	while (i < nb_seg)
	{
		inter = intersect_seg(&segments[i], ray);
		if (inter.dist >= 0 && inter.img_x >= 0 && inter.img_x <= 1)
			return (inter);
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
