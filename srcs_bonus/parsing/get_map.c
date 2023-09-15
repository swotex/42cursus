/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:35:50 by njegat            #+#    #+#             */
/*   Updated: 2023/07/26 19:41:51 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "errors.h"

void	check_line(int fd, char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1')
		{
			if (line[i] != 'N' && line[i] != 'S')
			{
				if (line[i] != 'W' && line[i] != 'E' && line[i] != 'D')
				{
					release_all(map, fd, line);
					exit_error_parsing(MFORMAT, NULL);
				}
			}
		}
		i++;
	}
}

char	*add_c(char *str, char c)
{
	char	*out;
	int		i;

	i = 0;
	out = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	if (out == NULL)
		return (NULL);
	if (str != NULL)
	{
		ft_strlcpy(out, str, ft_strlen(str) + 1);
		free(str);
	}
	while (out[i])
		i++;
	out[i] = c;
	out[i + 1] = '\0';
	return (out);
}

void	to_square(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	max_size;

	max_size = 0;
	i = 0;
	while (map->plan[i])
	{
		if (ft_strlen(map->plan[i]) > max_size)
			max_size = ft_strlen(map->plan[i]);
		i++;
	}
	i = 0;
	while (map->plan[i])
	{
		j = ft_strlen(map->plan[i]);
		while (max_size - j)
		{
			map->plan[i] = add_c(map->plan[i], ' ');
			j++;
		}
		i++;
	}
}

void	check_empty_line_map(int fd, char *line, t_map *map)
{
	int	i;

	while (line)
	{
		i = skip_set(line, " \t");
		if (line[i])
		{
			release_all(map, fd, line);
			exit_error_parsing(MEMPTY, NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	get_map(int fd, char *line, t_map *map)
{
	int	i;

	while (line)
	{
		i = skip_set(line, " \t");
		if (!line[i])
			break ;
		check_line(fd, line, map);
		map->plan = ft_strappend(line, map->plan);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		check_empty_line_map(fd, line, map);
	if (!map->plan)
	{
		release_all(map, fd, line);
		exit_error_parsing(IFILE, NULL);
	}
	to_square(map);
}
