/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:15:35 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/29 21:36:40 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(int move, t_player *player)
{
	if (move == LEFT)
	{
		player->dir -= 5;
	}
	if (move == RIGHT)
	{
		player->dir += 5;
	}
	player->dir += 360;
	player->dir = player->dir % 360;
}

void	mouse_rotate(t_data *data)
{
	int32_t	mouse_pos[2];
	int		add_dir;

	mlx_get_mouse_pos(data->mlx, &mouse_pos[0], &mouse_pos[1]);
	add_dir = (int)fabs(WIDTH / 2 - mouse_pos[0]) * 0.06;
	if (add_dir == 0)
		add_dir++;
	if (mouse_pos[0] < WIDTH / 2 && mouse_pos[0] >= 0
		&& mouse_pos[1] >= 0 && mouse_pos[1] < HEIGHT)
		data->player.dir -= add_dir;
	if (mouse_pos[0] > WIDTH / 2 && mouse_pos[0] < WIDTH
		&& mouse_pos[1] >= 0 && mouse_pos[1] < HEIGHT)
		data->player.dir += add_dir;
	if (mouse_pos[0] >= 0 && mouse_pos[0] < WIDTH
		&& mouse_pos[1] >= 0 && mouse_pos[1] < HEIGHT)
		mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
}
