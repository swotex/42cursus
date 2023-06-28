/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:31:39 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 04:15:37 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	ft_double_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

void	ft_free_matrix(t_data *data)
{
	int	i;

	i = 0;
	if (!data->matrix)
		return ;
	while (i < data->matrix_y)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}
