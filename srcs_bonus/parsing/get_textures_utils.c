/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:47:20 by njegat            #+#    #+#             */
/*   Updated: 2023/07/19 23:49:50 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define NONE 5

int	get_cardinal(char *line)
{
	if (line[2] != ' ' && line[2] != '\t')
		return (NONE);
	if (ft_strncmp(line, "NO", 2) == 0)
		return (N);
	if (ft_strncmp(line, "SO", 2) == 0)
		return (S);
	if (ft_strncmp(line, "WE", 2) == 0)
		return (W);
	if (ft_strncmp(line, "EA", 2) == 0)
		return (E);
	return (NONE);
}

int	is_duplicates(int cardinal, t_map *map)
{
	if (cardinal == N && map->texture[N])
		return (TRUE);
	if (cardinal == S && map->texture[S])
		return (TRUE);
	if (cardinal == W && map->texture[W])
		return (TRUE);
	if (cardinal == E && map->texture[E])
		return (TRUE);
	return (FALSE);
}
