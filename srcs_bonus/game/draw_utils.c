/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:51:02 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/25 23:15:27 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_bloc(const t_vec2 *pos, t_map map, int32_t color,
			mlx_image_t *image)
{
	int	x;
	int	y;

	y = pos->y - MINI_BLOC / 2;
	while (y < pos->y + MINI_BLOC / 2)
	{
		x = pos->x - MINI_BLOC / 2;
		while (x < pos->x + MINI_BLOC / 2)
		{
			if (pow(map.center_pos.x - x, 2) + pow(map.center_pos.y - y, 2)
				<= pow(map.radius, 2))
				mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_line(t_segment segment, int size, t_data *data, int32_t color)
{
	int		i;
	double	length;
	t_vec2	pix_pos;
	t_vec2	d;

	segment.p1 = scale_vec(&segment.p1, size);
	segment.p2 = scale_vec(&segment.p2, size);
	if (fabs(segment.p2.x - segment.p1.x) >= fabs(segment.p2.y - segment.p1.y))
		length = fabs(segment.p2.x - segment.p1.x);
	else
		length = fabs(segment.p2.y - segment.p1.y);
	d.x = (segment.p2.x - segment.p1.x) / length;
	d.y = (segment.p2.y - segment.p1.y) / length;
	pix_pos.x = WIDTH / 2 - (ft_strlen(data->map.plan[0]) / 2 * size)
		+ segment.p1.x - size / 2;
	pix_pos.y = HEIGHT / 2 - (array_len(data->map.plan) / 2 * size)
		+ segment.p1.y - size / 2;
	i = 1;
	while (i <= length)
	{
		mlx_put_pixel(data->image, pix_pos.x, pix_pos.y, color);
		pix_pos.x += d.x;
		pix_pos.y += d.y;
		i++;
	}
}

int	det_triangle(const t_vec2 *first, const t_vec2 *second, const t_vec2 *point)
{
	t_vec2	fp;
	t_vec2	sp;
	int		det;

	fp.x = point->x - first->x;
	fp.y = point->y - first->y;
	sp.x = point->x - second->x;
	sp.y = point->y - second->y;
	det = (fp.x * sp.y) - (fp.y * sp.x);
	if (det >= 0)
		return (1);
	return (-1);
}

int	bsp(const t_vec2 *triangle, const t_vec2 *point)
{
	int	det_apc;
	int	det_cpb;
	int	det_bpa;

	det_apc = det_triangle(&triangle[0], &triangle[2], point);
	det_cpb = det_triangle(&triangle[2], &triangle[1], point);
	det_bpa = det_triangle(&triangle[1], &triangle[0], point);
	if (det_apc == det_cpb && det_cpb == det_bpa)
		return (TRUE);
	return (FALSE);
}

void	add_player(const t_vec2 *pos, int dir, int size, mlx_image_t *image)
{
	int		x;
	int		y;
	double	rad;
	t_vec2	tgl[3];

	rad = dir * PI_DIV_180;
	tgl[0] = (t_vec2){pos->x + (size * cos(rad)), pos->y + (size * sin(rad))};
	rad = (dir - 180 - 30) * PI_DIV_180;
	size = sqrt(pow(size, 2) + pow(size, 2));
	tgl[1] = (t_vec2){pos->x + (size * cos(rad)), pos->y + (size * sin(rad))};
	rad = (dir - 180 + 30) * PI_DIV_180;
	tgl[2] = (t_vec2){pos->x + (size * cos(rad)), pos->y + (size * sin(rad))};
	y = pos->y - size;
	while (y < (pos->y + size))
	{
		x = pos->x - size;
		while (x < (pos->x + size))
		{
			if (bsp(tgl, &(t_vec2){x, y}))
				mlx_put_pixel(image, x, y, 0xD4AF37FF);
			x++;
		}
		y++;
	}
}
