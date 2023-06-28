/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:06:28 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:58:17 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

//For X - Y - Z on one time
void	ft_calcul_rotate(int x, int y, t_matrix *matrix, t_data *data)
{
	int	z;

	z = 0;
	if (matrix->z > 0 && (data->space / 2) >= 1)
		z += ((matrix->z + data->offset_z) * (data->space / 2)) / 3;
	else
		z += matrix->z / 2;
	matrix->y = (y * cos(data->rot_x)) - (z * sin(data->rot_x));
	z = (y * sin(data->rot_x)) + (z * cos(data->rot_x));
	y = matrix->y;
	matrix->x = x * cos(data->rot_y) + z * sin(data->rot_y);
	x = matrix->x;
	matrix->x = x * cos(data->rot_z) - y * sin(data->rot_z);
	matrix->y = x * sin(data->rot_z) + y * cos(data->rot_z);
}

void	ft_make_spin(t_mlx *mlx)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < mlx->data.matrix_y)
	{
		j = 0;
		while (j < mlx->data.matrix_x)
		{
			x = mlx->data.matrix[i][j].x;
			y = mlx->data.matrix[i][j].y;
			ft_calcul_rotate(x, y, &mlx->data.matrix[i][j], &mlx->data);
			j++;
		}
		i++;
	}
}
