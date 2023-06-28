/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_suit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:14:26 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:25:00 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_set_origin_of_matrix(t_data *data)
{
	double	origin_x;
	double	origin_y;

	origin_x = data->matrix[0][data->matrix_x - 1].x - data->matrix[0][0].x;
	origin_x /= 2;
	origin_y = data->matrix[data->matrix_y - 1][0].y - data->matrix[0][0].y;
	origin_y /= 2;
	data->origin_x = origin_x;
	data->origin_y = origin_y;
}

void	ft_set_matrix_origin(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->matrix_y)
	{
		j = 0;
		while (j < data->matrix_x)
		{
			data->matrix[i][j].x -= data->origin_x;
			data->matrix[i][j].y -= data->origin_y;
			j++;
		}
		i++;
	}
	data->origin_x = 0;
	data->origin_y = 0;
}
