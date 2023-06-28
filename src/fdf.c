/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:54:29 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 03:53:05 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_set_pos_matrix(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->matrix_y)
	{
		j = 0;
		while (j < data->matrix_x)
		{
			data->matrix[i][j].x += data->pos_x;
			data->matrix[i][j].y += data->pos_y;
			j++;
		}
		i++;
	}
	data->origin_x = data->pos_x;
	data->origin_y = data->pos_y;
}

void	ft_init_data(t_mlx *mlx)
{
	mlx->data.space = (mlx->screen_y / mlx->data.matrix_y) / 2;
	if (mlx->data.space % 2)
		mlx->data.space++;
	if (mlx->data.space < 6)
		mlx->data.space = 6;
	mlx->data.rot_x = 18 * (M_PI / 180);
	mlx->data.rot_y = -30 * (M_PI / 180);
	mlx->data.rot_z = 36 * (M_PI / 180);
	mlx->data.pos_x = mlx->screen_x / 2;
	mlx->data.pos_y = mlx->screen_y / 2;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (1);
	mlx.screen_x = 1920;
	mlx.screen_y = 1080;
	if (ft_file_handler(argv[1], &mlx))
		return (1);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.screen_x, mlx.screen_y, "FDF");
	mlx.img.img = mlx_new_image(mlx.mlx, mlx.screen_x, mlx.screen_y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	ft_hooks_handler(&mlx);
	ft_make_spin(&mlx);
	ft_set_pos_matrix(&mlx.data);
	ft_print_matrix(&mlx);
	mlx_loop(mlx.mlx);
}
