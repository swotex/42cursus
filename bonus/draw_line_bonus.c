/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:53:20 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:26:32 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_dda(t_matrix *pt1, t_matrix *pt2, t_mlx *mlx, int color)
{
	float	x;
	float	y;
	int		i;

	mlx->dda.dx = pt2->x - pt1->x;
	mlx->dda.dy = pt2->y - pt1->y;
	mlx->dda.steps = (int)fmax(fabs(mlx->dda.dx), fabs(mlx->dda.dy));
	mlx->dda.x_increment = mlx->dda.dx / (float)mlx->dda.steps;
	mlx->dda.y_increment = mlx->dda.dy / (float)mlx->dda.steps;
	x = pt1->x;
	y = pt1->y;
	i = 0;
	while (i <= mlx->dda.steps)
	{
		if (x > 0 && y > 0 && x < mlx->screen_x && y < mlx->screen_y)
			my_mlx_pixel_put(&mlx->img, (int)x, (int)y, color);
		x += mlx->dda.x_increment;
		y += mlx->dda.y_increment;
		i++;
	}
}
