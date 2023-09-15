/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:50:44 by njegat            #+#    #+#             */
/*   Updated: 2023/07/25 18:21:32 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "errors.h"

void	quit(t_map *map, int fd, char *line, int pflag)
{
	release_all(map, fd, line);
	if (pflag == 1)
		exit_error_parsing(FCOLOR, "digit");
	if (pflag == 2)
		exit_error_parsing(FCOLOR, "int too long or non-existent");
	if (pflag == 3)
		exit_error_parsing(FCOLOR, "size");
	if (pflag == 4)
		exit_error_parsing(FCOLOR, "duplicate color");
	else
		exit_error_parsing(FCOLOR, "default exit");
}

void	rgb_to_hex(t_map *map, int *rgb, int flag)
{
	if (flag == 'F')
	{
		map->f_color = ft_pixel(rgb[0], rgb[1], rgb[2]);
	}
	else if (flag == 'C')
	{
		map->c_color = ft_pixel(rgb[0], rgb[1], rgb[2]);
	}
}

void	init_rgb(int *rgb)
{
	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
}
