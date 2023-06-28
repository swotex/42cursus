/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:09:31 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:12:01 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	ft_free_matrix(&mlx->data);
	exit(0);
}

static int	ft_key(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		ft_exit(mlx);
	return (0);
}

void	ft_hooks_handler(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 1L << 17, &ft_exit, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, &ft_key, mlx);
}
