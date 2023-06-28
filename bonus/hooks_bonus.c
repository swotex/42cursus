/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:09:31 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:51:21 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	ft_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	ft_free_matrix(&mlx->data);
	exit(0);
}

static int	ft_key_untils(int keycode, t_mlx *mlx)
{
	if (keycode == 112)
		ft_init_data(mlx);
	else if (keycode == 49)
	{
		mlx->data.rot_x = 0;
		mlx->data.rot_y = 0;
		mlx->data.rot_z = 0;
	}
	else if (keycode == 50)
	{
		mlx->data.rot_x = 90 * (M_PI / 180);
		mlx->data.rot_y = 90 * (M_PI / 180);
		mlx->data.rot_z = 0;
	}
	else
		return (0);
	ft_clear(mlx);
	ft_zoom(&mlx->data);
	ft_set_origin_of_matrix(&mlx->data);
	ft_set_matrix_origin(&mlx->data);
	ft_make_spin(mlx);
	ft_set_pos_matrix(&mlx->data);
	ft_print_matrix(mlx);
	return (1);
}

static int	ft_key_untils_suit(int keycode, t_mlx *mlx)
{
	if (keycode == 99)
		mlx->data.set_color++;
	else
		return (0);
	ft_clear(mlx);
	ft_zoom(&mlx->data);
	ft_set_origin_of_matrix(&mlx->data);
	ft_set_matrix_origin(&mlx->data);
	ft_make_spin(mlx);
	ft_set_pos_matrix(&mlx->data);
	ft_print_matrix(mlx);
	return (1);
}

static int	ft_key_mana(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		ft_exit(mlx);
	else if (ft_shift(keycode, mlx))
		return (0);
	else if (ft_up_down_top(keycode, mlx))
		return (0);
	else if (ft_rotate_hook(keycode, mlx))
		return (0);
	else if (ft_key_untils(keycode, mlx))
		return (0);
	else if (ft_key_untils_suit(keycode, mlx))
		return (0);
	return (0);
}

void	ft_hooks_handler(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 1L << 17, &ft_exit, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, &ft_key_mana, mlx);
	mlx_mouse_hook(mlx->win, &ft_scroll, mlx);
}
