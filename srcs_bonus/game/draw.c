/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:48:40 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/30 19:25:45 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_circle(const t_vec2 *pos, int radius, int32_t color,
			mlx_image_t *image)
{
	int	x;
	int	y;

	y = pos->y - radius;
	while (y < pos->y + radius)
	{
		x = pos->x - radius;
		while (x < pos->x + radius)
		{
			if (pow(pos->x - x, 2) + pow(pos->y - y, 2) <= pow(radius, 2))
				mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_background(t_data *data, int32_t ceiling, int32_t floor)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y <= HEIGHT / 2)
				mlx_put_pixel(data->image, x, y, ceiling);
			else
				mlx_put_pixel(data->image, x, y, floor);
			x++;
		}
		y++;
	}
}

void	draw_mini(t_map map, mlx_image_t *image, t_player player)
{
	int		x;
	int		y;
	t_vec2	pos;
	int32_t	color;

	y = 0;
	draw_circle(&map.center_pos, map.radius, 0xB68C66FF, image);
	pos.y = map.center_pos.y - player.pos.y * MINI_BLOC + MINI_BLOC / 2;
	while (map.plan[y])
	{
		x = 0;
		pos.x = map.center_pos.x - player.pos.x * MINI_BLOC + MINI_BLOC / 2;
		while (map.plan[y][x])
		{
			color = map_color(map.plan[y][x]);
			fill_bloc(&pos, map, color, image);
			pos.x += MINI_BLOC;
			x++;
		}
		pos.y += MINI_BLOC;
		y++;
	}
	add_player(&map.center_pos, player.dir, MINI_BLOC / 2, image);
}

void	draw_wall(t_inter *inter, int px, double diff_rad, t_data *data)
{
	int		size;
	int		starts[2];
	int		py;
	int32_t	color;

	inter->dist *= cos(diff_rad);
	size = fabs(data->screen_dist / (inter->dist + 0.0001));
	starts[1] = (HEIGHT / 2.0) - (size / 2.0);
	py = 0;
	starts[0] = 0;
	if (starts[1] < 0)
	{
		starts[0] = -starts[1];
		starts[1] = 0;
	}
	while (py < size)
	{
		if (starts[1] + py >= HEIGHT)
			break ;
		color = get_pixel_texture(data->map.texture[inter->dir], inter->img_x,
				(double)(py + starts[0]) / (double)size);
		mlx_put_pixel(data->image, px, starts[1] + py, color);
		py++;
	}
}

void	draw_segments(t_segment *segments, int size, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_seg)
	{
		draw_line(segments[i], size, data, 0x00FF00FF);
		i++;
	}
}
