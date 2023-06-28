/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:31:46 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:12:45 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	**ft_file_to_array(char *file_name)
{
	int		fd;
	char	*tmp;
	char	*out_file;
	char	**output;

	fd = open(file_name, 0);
	if (fd < 0)
		return (NULL);
	out_file = ft_calloc(1, sizeof(char));
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		out_file = ft_strjoin(out_file, tmp);
		free(tmp);
	}
	if (*out_file)
		output = ft_split(out_file, '\n');
	else
		output = NULL;
	free(out_file);
	close(fd);
	return (output);
}

static int	ft_check_filename(char *file_name)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(file_name) - 4)
		i++;
	file_name += i;
	if (ft_strncmp(file_name, ".fdf", 4))
		return (1);
	return (0);
}

int	ft_file_handler(char *file_name, t_mlx *mlx)
{
	char	**file;

	if (ft_check_filename(file_name))
		return (1);
	file = ft_file_to_array(file_name);
	if (!file)
		return (1);
	if (ft_matrix_handler(file, mlx))
		return (1);
	return (0);
}
