/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:45:03 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:35:00 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	ft_legend_background(t_mlx *mlx)
{
	int			i;
	t_matrix	point1;
	t_matrix	point2;

	i = 623;
	point1.x = 20;
	point2.x = 150;
	while (i < 1023)
	{
		point1.y = i;
		point2.y = i;
		ft_dda(& point1, &point2, mlx, 0x0014213d);
		i++;
	}
}

static void	ft_legend_outline(t_mlx *mlx)
{
	t_matrix	point1;
	t_matrix	point2;

	point1.x = 20;
	point2.x = 150;
	point1.y = 623;
	point2.y = 623;
	ft_dda(&point1, &point2, mlx, 0x00FF0000);
	point2.x = 20;
	point2.y = 1023;
	ft_dda(&point1, &point2, mlx, 0x00FF0000);
	point1.y = 1023;
	point2.x = 150;
	ft_dda(&point1, &point2, mlx, 0x00FF0000);
	point1.x = 150;
	point1.y = 623;
	ft_dda(&point1, &point2, mlx, 0x00FF0000);
	point1.x = 21;
	point1.y = 733;
	point2.x = 149;
	point2.y = 733;
	ft_dda(&point1, &point2, mlx, 0x00441878);
	point1.y = 803;
	point2.y = 803;
	ft_dda(&point1, &point2, mlx, 0x00441878);
}

void	ft_display_legend(t_mlx *mlx)
{
	ft_legend_background(mlx);
	ft_legend_outline(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 30, 653, WHITE, "Rotate on x = W S");
	mlx_string_put(mlx->mlx, mlx->win, 30, 683, WHITE, "Rotate on y = A D");
	mlx_string_put(mlx->mlx, mlx->win, 30, 713, WHITE, "Rotate on z = Q E");
	mlx_string_put(mlx->mlx, mlx->win, 30, 753, WHITE, "Top view = 1");
	mlx_string_put(mlx->mlx, mlx->win, 30, 783, WHITE, "Right view = 2");
	mlx_string_put(mlx->mlx, mlx->win, 30, 823, WHITE, "Zoom = mouse wheel");
	mlx_string_put(mlx->mlx, mlx->win, 30, 853, WHITE, "Reset = P");
	mlx_string_put(mlx->mlx, mlx->win, 30, 883, WHITE, "Vertex size = + -");
	mlx_string_put(mlx->mlx, mlx->win, 30, 913, WHITE, "Shift = arrows");
	mlx_string_put(mlx->mlx, mlx->win, 30, 943, WHITE, "Color = C");
	mlx_string_put(mlx->mlx, mlx->win, 30, 973, WHITE, "3 preset colors :");
	mlx_string_put(mlx->mlx, mlx->win, 30, 1003, WHITE, "2 default & 1 file");
}
