/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:17:50 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 04:15:07 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

unsigned int	ft_color_palette1_neg(int z, int z_calc)
{
	if (z > -10 * z_calc)
		return (0x00d8f3dc);
	if (z > -15 * z_calc)
		return (0x00b7e4c7);
	if (z > -20 * z_calc)
		return (0x0095d5b2);
	if (z > -25 * z_calc)
		return (0x0074c69d);
	if (z > -30 * z_calc)
		return (0x0052b788);
	if (z > -35 * z_calc)
		return (0x0040916c);
	if (z > -40 * z_calc)
		return (0x002d6a4f);
	return (0x002d6a4f);
}

unsigned int	ft_color_palette1_pos(int z, int z_calc)
{
	int	color;

	if (z < 0)
	{
		color = ft_color_palette1_neg(z, z_calc);
		return (color);
	}
	if (z < 10 * z_calc)
		return (0x0080ffdb);
	if (z < 15 * z_calc)
		return (0x0072efdd);
	if (z < 20 * z_calc)
		return (0x0064dfdf);
	if (z < 25 * z_calc)
		return (0x0056cfe1);
	if (z < 30 * z_calc)
		return (0x0048bfe3);
	if (z < 35 * z_calc)
		return (0x004ea8de);
	if (z < 40 * z_calc)
		return (0x005390d9);
	return (0x005e60ce);
}

unsigned int	ft_color_palette2_neg(int z, int z_calc)
{
	if (z > -10 * z_calc)
		return (0x00006994);
	if (z > -15 * z_calc)
		return (0x00007ea5);
	if (z > -20 * z_calc)
		return (0x0000aabb);
	if (z > -25 * z_calc)
		return (0x0000cdbe);
	if (z > -30 * z_calc)
		return (0x0037e7a4);
	if (z > -35 * z_calc)
		return (0x0089f46b);
	if (z > -40 * z_calc)
		return (0x00b2f746);
	return (0x00def707);
}

unsigned int	ft_color_palette2_pos(int z, int z_calc)
{
	int	color;

	if (z < 0)
	{
		color = ft_color_palette2_neg(z, z_calc);
		return (color);
	}
	if (z < 10 * z_calc)
		return (0x00d16ba5);
	if (z < 15 * z_calc)
		return (0x00ba83ca);
	if (z < 20 * z_calc)
		return (0x009a9ae1);
	if (z < 25 * z_calc)
		return (0x0079b3f4);
	if (z < 30 * z_calc)
		return (0x0069bff8);
	if (z < 35 * z_calc)
		return (0x0052cffe);
	if (z < 40 * z_calc)
		return (0x0041dfff);
	return (0x005ffbf1);
}

unsigned int	ft_color_handler(t_data *data, int i, int j)
{
	int	color;
	int	set_color;
	int	z;

	color = WHITE;
	set_color = data->set_color % 3;
	if (data->matrix[i][j].z > 0 && (data->space / 2) >= 1)
		z = ((data->matrix[i][j].z + data->offset_z) * (data->space / 2)) / 3;
	else if (data->matrix[i][j].z > 0)
		z = (data->matrix[i][j].z + data->offset_z) / 2;
	else
		z = data->matrix[i][j].z;
	if (z == 0)
		return (color);
	if (set_color == 0)
		color = ft_color_palette1_pos(z, (data->space / 2));
	else if (set_color == 1)
		color = ft_color_palette2_pos(z, (data->space / 2));
	else
		return (data->matrix[i][j].color);
	return (color);
}
