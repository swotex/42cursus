/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_set_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:24:28 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:41:19 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	ft_error_matrix(char **array, t_matrix **matrix, int i)
{
	while (i > 0)
	{
		free(matrix[i - 1]);
		i--;
	}
	free(matrix);
	ft_double_free(array);
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_array_to_matrix(char **array, t_data *data)
{
	int			i;
	t_matrix	**matrix;

	data->matrix_x = ft_nb_digit(array[0]);
	data->matrix_y = ft_arraylen(array);
	matrix = malloc(sizeof(t_matrix *) * data->matrix_y);
	if (!matrix)
	{
		ft_double_free(array);
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (array[i])
	{
		if (ft_nb_digit(array[i]) != data->matrix_x)
			ft_error_matrix(array, matrix, i);
		matrix[i] = malloc(sizeof(t_matrix) * data->matrix_x);
		if (!matrix[i])
			ft_error_matrix(array, matrix, i);
		i++;
	}
	data->matrix = matrix;
}

static void	ft_set_point(t_data *data, int i, int y, char **value)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	while (j < data->matrix_x)
	{
		data->matrix[i][j].x = x;
		data->matrix[i][j].y = y;
		data->matrix[i][j].z = ft_atoll(value[j]);
		if (ft_found_color(value[j]))
			data->matrix[i][j].color = ft_get_color(value[j]);
		else
			data->matrix[i][j].color = WHITE;
		j++;
		x += data->space;
	}
}

static int	ft_set_pos(t_data *data, char **array)
{
	int		i;
	int		y;
	char	**tmp;

	i = 0;
	y = 0;
	while (i < data->matrix_y)
	{
		tmp = ft_split(array[i], ' ');
		if (!tmp)
			return (1);
		ft_set_point(data, i, y, tmp);
		ft_double_free(tmp);
		i++;
		y += data->space;
	}
	return (0);
}

int	ft_matrix_handler(char **array, t_mlx *mlx)
{
	ft_array_to_matrix(array, &mlx->data);
	ft_init_data(mlx);
	if (ft_set_pos(&mlx->data, array))
	{
		ft_double_free(array);
		ft_free_matrix(&mlx->data);
		return (1);
	}
	ft_double_free(array);
	ft_set_origin_of_matrix(&mlx->data);
	ft_set_matrix_origin(&mlx->data);
	return (0);
}
