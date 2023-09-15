/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:48:40 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/25 20:55:53 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
