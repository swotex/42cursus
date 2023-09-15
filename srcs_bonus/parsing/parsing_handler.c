/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 04:09:48 by njegat            #+#    #+#             */
/*   Updated: 2023/07/30 19:33:11 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "errors.h"
#include <fcntl.h>
#include <stdio.h>

void	check_extension_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		exit_error_parsing(FEXT, NULL);
	if (ft_strncmp(&file[len - 4], ".cub", 4))
		exit_error_parsing(FEXT, NULL);
	if (!ft_strncmp(&file[len - 5], "/.cub", 5))
		exit_error_parsing(FEXT, NULL);
}

void	parsing_handler(int argc, char **argv, t_data *data)
{
	int		fd;
	char	*line;

	if (argc != 2)
		exit_error_parsing(ARGS, NULL);
	check_extension_file(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_error_parsing(OFILE, argv[1]);
	line = NULL;
	line = get_textures(fd, line, &data->map);
	line = get_colors(fd, line, &data->map);
	get_map(fd, line, &data->map);
	close(fd);
	check_map(&data->map);
	open_door_txt("./textures/mdoor.png", &data->map);
	find_segments(data, data->map.plan);
	find_doors(data, data->map.plan);
}
