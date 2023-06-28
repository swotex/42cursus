/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 04:09:48 by njegat            #+#    #+#             */
/*   Updated: 2023/06/09 17:27:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <fcntl.h>
#include <stdio.h>
#define EXT 12
#define ARGS 13
#define FILE 14
#define MAP 15
#define COLOR 16
#define TXT 17
#define OTXT 18
#define MTXT 19
#define FORMAT 20
// #define MALLOC 112

void	exit_error_parsing(int flag)
{
	ft_printf_fd(2, "Error\n");
	if (flag == EXT)
		ft_printf_fd(2, "Invalid extention\n");
	if (flag == ARGS)
		ft_printf_fd(2, "Invalid number arguments\n");
	if (flag == FILE)
		perror(0);
	if (flag == MTXT)
		ft_printf_fd(2, "Too many or not enough textures\n");
	if (flag == OTXT)
		ft_printf_fd(2, "Open texture error\n");
	// if (flag == MAP)
	// if (flag == FORMAT)
	// if (flag == COLOR)
	// if (flag == TXT)
	exit(1);
}

// void	exit_error_common(int flag)
// {
// 	ft_printf_fd(2, "Error\n");
// 	if (flag == MALLOC)
// 		ft_printf_fd(2, "Malloc error\n");
// 	exit(1);
// }

void	extention_check(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		exit_error_parsing(EXT);
	if (ft_strncmp(&file[len - 4], ".cub", 4))
		exit_error_parsing(EXT);
	if (!ft_strncmp(&file[len - 5], "/.cub", 5))
		exit_error_parsing(EXT);
}

int	open_texture(int face, char **file, int i, t_map *map)
{
	int		fd;
	char	*tmp;

	tmp = ft_strtrim(file[i] + 2, " \t\n");
	printf("%s\n", tmp);
	if (!tmp)
		return (0);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (fd == -1)
	{
		free(file);
		exit_error_parsing(OTXT);
	}
	if (face == 1)
		map->no_fd = fd;
	else if (face == 2)
		map->so_fd = fd;
	else if (face == 3)
		map->we_fd = fd;
	else if (face == 4)
		map->ea_fd = fd;
	else
		return (0);
	return (1);
}

void	check_texture(char **file, t_map *map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (file[i])
	{
		j = skip_set(file[i], " \t");
		if (ft_strncmp(file[i] + j, "NO", 2) == 0)
			check += open_texture(1, file, i, map);
		else if (ft_strncmp(file[i] + j, "SO", 2) == 0)
			check += open_texture(2, file, i, map);
		else if (ft_strncmp(file[i] + j, "WE", 2) == 0)
			check += open_texture(3, file, i, map);
		else if (ft_strncmp(file[i] + j, "EA", 2) == 0)
			check += open_texture(4, file, i, map);
		else if (file[i][j] != 0 && file[i][j] != '\n')
			break ;
		i++;
	}
	if (check != 4)
	{
		ft_free_tab(file);
		exit_error_parsing(MTXT);
	}
}

void	parse_file(int fd, t_map *map)
{
	char	*tmp;
	char	*str;
	char	**file;

	str = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = ft_strjoin_free_first(str, tmp);
		str = ft_strjoin_free_first(str, "\n");
		free(tmp);
		tmp = get_next_line(fd);
	}
	file = ft_split(str, '\n');
	free(str);
	close(fd);
	check_texture(file, map);
//format fichier (en continu)
//txt
//color
//map
//si erreur close into exit
	ft_free_tab(file);
}

int	parsing_handler(int argc, char **argv, t_map *map)
{
	int	fd;

	if (argc != 2)
		exit_error_parsing(ARGS);
	extention_check(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_error_parsing(FILE);
	parse_file(fd, map);
	return (fd);
}
