/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:22:38 by njegat            #+#    #+#             */
/*   Updated: 2023/07/19 23:48:49 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "errors.h"
#include <fcntl.h>

#define NONE 5

void	open_texture(char *line, int fd, int cardinal, t_map *map)
{
	int		i;
	char	*tmp;

	i = skip_set(line, " \t");
	i += 2;
	tmp = ft_strtrim(line + i, " \t");
	map->texture[cardinal] = mlx_load_png(tmp);
	free(tmp);
	if (!map->texture[cardinal])
	{
		release_all(map, fd, line);
		exit_error_parsing(OFILE, "Texture error");
	}
}

void	check_opened(int fd, char *line, t_map *map)
{
	int	i;

	if (!map->texture[N] || !map->texture[S]
		|| !map->texture[E] || !map->texture[W])
	{
		i = skip_set(line, " \t");
		if (line[i] == 'F' || line[i] == 'C')
		{
			release_all(map, fd, line);
			exit_error_parsing(MISST, NULL);
		}
		else
		{
			release_all(map, fd, line);
			exit_error_parsing(FORMAT, NULL);
		}
	}
}

int	check_error(int fd, char *line, int i, t_map *map)
{
	int		cardinal;

	cardinal = get_cardinal(line + i);
	if (cardinal == NONE)
		return (cardinal);
	if (is_duplicates(cardinal, map) == TRUE)
	{
		release_all(map, fd, line);
		exit_error_parsing(CDUP, NULL);
	}
	if (check_texture_ext(line) == FALSE)
	{
		release_all(map, fd, line);
		exit_error_parsing(FEXT, NULL);
	}
	return (cardinal);
}

char	*get_textures(int fd, char *line, t_map *map)
{
	int		i;
	int		cardinal;

	line = get_next_line(fd);
	while (line != NULL)
	{
		i = skip_set(line, " \t");
		if (line[i])
		{
			cardinal = check_error(fd, line, i, map);
			if (cardinal == NONE)
				break ;
			open_texture(line, fd, cardinal, map);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		release_all(map, fd, line);
		exit_error_parsing(IFILE, NULL);
	}
	check_opened(fd, line, map);
	return (line);
}
