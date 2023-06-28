/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:04:14 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:10:07 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_print_matrix(t_mlx *mlx)
{
	t_data	data;
	int		i;
	int		j;

	i = 0;
	data = mlx->data;
	while (i < mlx->data.matrix_y)
	{
		j = 0;
		while (j < mlx->data.matrix_x)
		{
			if (j < mlx->data.matrix_x - 1)
				ft_dda(&data.matrix[i][j], &data.matrix[i][j + 1], mlx, WHITE);
			if (i < mlx->data.matrix_y - 1)
				ft_dda(&data.matrix[i][j], &data.matrix[i + 1][j], mlx, WHITE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
