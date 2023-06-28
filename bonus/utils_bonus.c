/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:17:30 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:43:13 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	ft_nb_digit(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i])
		{
			while (str[i] != ' ' && str[i])
				i++;
			count++;
		}
	}
	return (count);
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

void	ft_zoom(t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = 0;
	if (data->space < 2)
		data->space = 2;
	while (i < data->matrix_y)
	{
		j = 0;
		x = 0;
		while (j < data->matrix_x)
		{
			data->matrix[i][j].x = x;
			data->matrix[i][j].y = y;
			j++;
			x += data->space;
		}
		i++;
		y += data->space;
	}
}

int	ft_found_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

unsigned int	ft_get_color(char *str)
{
	int				i;
	unsigned int	output;

	i = 0;
	while (*str && *str != 'x')
		str++;
	str++;
	output = ft_atoi_base(str, 16);
	return (output);
}
