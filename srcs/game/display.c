/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 03:12:27 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/25 20:55:55 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display(t_data *data)
{
	if (data->image)
		mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
	draw_background(data, data->map.c_color, data->map.f_color);
	raycasting(data->segments, data->nb_seg, data->player, data);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
}
