/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:04:14 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 06:06:17 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	ft_print_matrix(t_mlx *mlx)
{
	t_data			data;
	int				i;
	int				j;
	unsigned int	color;

	data = mlx->data;
	i = 0;
	while (i < mlx->data.matrix_y)
	{
		j = 0;
		while (j < mlx->data.matrix_x)
		{
			color = ft_color_handler(&mlx->data, i, j);
			if (j < mlx->data.matrix_x - 1)
				ft_dda(&data.matrix[i][j], &data.matrix[i][j + 1], mlx, color);
			if (i < mlx->data.matrix_y - 1)
				ft_dda(&data.matrix[i][j], &data.matrix[i + 1][j], mlx, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	ft_display_legend(mlx);
}

void	ft_clear(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->screen_x, mlx->screen_y);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
}
