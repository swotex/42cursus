/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_suit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:27:55 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:49:24 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	ft_rotate_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 97)
		mlx->data.rot_y -= 2 * (M_PI / 180);
	else if (keycode == 100)
		mlx->data.rot_y += 2 * (M_PI / 180);
	else if (keycode == 119)
		mlx->data.rot_x += 2 * (M_PI / 180);
	else if (keycode == 115)
		mlx->data.rot_x -= 2 * (M_PI / 180);
	else if (keycode == 113)
		mlx->data.rot_z -= 2 * (M_PI / 180);
	else if (keycode == 101)
		mlx->data.rot_z += 2 * (M_PI / 180);
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

int	ft_up_down_top(int keycode, t_mlx *mlx)
{
	if (keycode == 45)
		mlx->data.offset_z -= 2;
	else if (keycode == 61)
		mlx->data.offset_z += 2;
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

int	ft_scroll(int keycode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (keycode == 5)
		mlx->data.space -= 2;
	if (keycode == 4)
		mlx->data.space += 2;
	ft_clear(mlx);
	ft_zoom(&mlx->data);
	ft_set_origin_of_matrix(&mlx->data);
	ft_set_matrix_origin(&mlx->data);
	ft_make_spin(mlx);
	ft_set_pos_matrix(&mlx->data);
	ft_print_matrix(mlx);
	return (0);
}

int	ft_shift(int keycode, t_mlx *mlx)
{
	if (keycode == 65361)
		mlx->data.pos_x -= 10;
	else if (keycode == 65362)
		mlx->data.pos_y -= 10;
	else if (keycode == 65364)
		mlx->data.pos_y += 10;
	else if (keycode == 65363)
		mlx->data.pos_x += 10;
	else
		return (0);
	ft_clear(mlx);
	ft_set_matrix_origin(&mlx->data);
	ft_set_pos_matrix(&mlx->data);
	ft_print_matrix(mlx);
	return (1);
}
