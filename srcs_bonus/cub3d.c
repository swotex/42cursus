/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 03:45:49 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/28 23:59:04 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->texture[N] = NULL;
	map->texture[S] = NULL;
	map->texture[E] = NULL;
	map->texture[W] = NULL;
	map->texture[D] = NULL;
	map->c_color = -1;
	map->f_color = -1;
	map->plan = NULL;
	map->display = FALSE;
	if (WIDTH > HEIGHT)
	{
		map->center_pos = (t_vec2){WIDTH * 0.91, HEIGHT * 0.81};
		map->radius = WIDTH * 0.083;
	}
	else if (WIDTH < HEIGHT)
	{
		map->center_pos = (t_vec2){WIDTH * 0.84, HEIGHT * 0.91};
		map->radius = HEIGHT * 0.083;
	}
	else
	{
		map->center_pos = (t_vec2){WIDTH * 0.903, HEIGHT * 0.903};
		map->radius = WIDTH * 0.083;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_map(&data.map);
	data.image = NULL;
	parsing_handler(argc, argv, &data);
	find_player(data.map.plan, &data.player);
	launch_game(&data);
	release_all(&data.map, -1, NULL);
	free(data.segments);
	free(data.doors);
	return (0);
}
