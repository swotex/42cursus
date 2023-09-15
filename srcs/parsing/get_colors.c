/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:38:44 by njegat            #+#    #+#             */
/*   Updated: 2023/07/30 01:47:15 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "errors.h"
#define F 41
#define C 42

int	already_exist(t_map *map, int flag)
{
	if (flag == 'F')
	{
		if (map->f_color == -1)
		{
			return (FALSE);
		}
		return (TRUE);
	}
	else if (flag == 'C')
	{
		if (map->c_color == -1)
		{
			return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

void	check_nb_comma(char *line, int fd, t_map *map)
{
	int	i;
	int	comma;

	comma = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
	{
		release_all(map, fd, line);
		exit_error_parsing(FCOLOR, "number of comma");
	}
}

int	check_size_color(char *line, int fd, t_map *map, int i)
{
	int	j;
	int	color_size;

	j = 0;
	color_size = 0;
	while (line[i + j] && line[i + j] != ',')
	{
		if (ft_isdigit(line[i + j]) == FALSE)
		{
			j += skip_set(line + i + j, " \t");
			if (line[i + j] != ',' && line[i + j] != 0)
				quit(map, fd, line, 1);
		}
		else
		{
			j++;
			color_size++;
		}
	}
	if (color_size > 3 || color_size <= 0)
		quit(map, fd, line, 2);
	return (j);
}

void	set_color(char *line, int fd, t_map *map)
{
	int	i;
	int	j;
	int	pos;
	int	rgb[3];

	i = 0;
	pos = 0;
	while (line[i] && pos < 3)
	{
		i += skip_set(line, " \t");
		i++;
		i += skip_set(line + i, " \t");
		j = check_size_color(line, fd, map, i);
		rgb[pos] = ft_atoi(line + i);
		if (rgb[pos] > 255 || rgb[pos] < 0)
			quit(map, fd, line, 3);
		if (already_exist(map, line[skip_set(line, " \t")]) == TRUE)
			quit(map, fd, line, 4);
		pos++;
		i += j;
	}
	if (rgb[0] == -1 || rgb[1] == -1 || rgb[2] == -1)
		quit(map, fd, line, 2);
	rgb_to_hex(map, rgb, line[skip_set(line, " \t")]);
}

char	*get_colors(int fd, char *line, t_map *map)
{
	int	i;

	while (line)
	{
		i = skip_set(line, " \t");
		if (!line[i])
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (is_flag_color(line + i) == FALSE)
			break ;
		check_nb_comma(line, fd, map);
		set_color(line, fd, map);
		free(line);
		line = get_next_line(fd);
	}
	if (map->c_color == -1 || map->f_color == -1)
	{
		release_all(map, fd, line);
		exit_error_parsing(FCOLOR, "missing color");
	}
	return (line);
}
