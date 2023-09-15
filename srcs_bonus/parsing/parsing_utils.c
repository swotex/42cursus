/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:24:07 by njegat            #+#    #+#             */
/*   Updated: 2023/07/28 20:22:14 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	release_all(t_map *map, int fd, char *line)
{
	if (fd > 2)
		close(fd);
	if (map->texture[N])
		mlx_delete_texture(map->texture[N]);
	if (map->texture[S])
		mlx_delete_texture(map->texture[S]);
	if (map->texture[E])
		mlx_delete_texture(map->texture[E]);
	if (map->texture[W])
		mlx_delete_texture(map->texture[W]);
	if (map->texture[D])
		mlx_delete_texture(map->texture[D]);
	if (line)
		free(line);
	if (map->plan)
		ft_free_tab(map->plan);
}

int	check_texture_ext(char *line)
{
	int		len;
	char	*tmp;

	tmp = ft_strtrim(line, " \t");
	if (!tmp)
		return (FALSE);
	len = ft_strlen(tmp);
	if (len < 5)
	{
		free(tmp);
		return (FALSE);
	}
	if (ft_strncmp(&tmp[len - 4], ".png", 4))
	{
		free(tmp);
		return (FALSE);
	}
	if (!ft_strncmp(&tmp[len - 5], "/.png", 5))
	{
		free(tmp);
		return (FALSE);
	}
	free(tmp);
	return (TRUE);
}

int	is_flag_color(char *line)
{
	if (line[1] != ' ' && line[1] != '\t')
		return (FALSE);
	if (line[0] != 'F' && line[0] != 'C')
		return (FALSE);
	return (TRUE);
}

void	init_player(t_player *player, int x, int y, char **plan)
{
	const char	dir[4] = "ESWN";

	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	player->dir = 0;
	while (dir[player->dir])
	{
		if (dir[player->dir] == plan[y][x])
			break ;
		player->dir++;
	}
	player->dir *= 90;
	player->speed = 0.1;
}

void	find_player(char **plan, t_player *player)
{
	int			x;
	int			y;

	y = 0;
	while (plan[y])
	{
		x = 0;
		while (plan[y][x])
		{
			if (is_player(plan[y][x]))
				break ;
			x++;
		}
		if (is_player(plan[y][x]))
			break ;
		y++;
	}
	init_player(player, x, y, plan);
}
