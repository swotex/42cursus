/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 03:09:21 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/30 20:32:50 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_move(t_player *player, char **map, double rad)
{
	double	move_y;
	double	move_x;

	move_x = player->pos.x + (player->speed * sin(rad));
	move_y = player->pos.y - (player->speed * cos(rad));
	if (map[(int)player->pos.y][(int)move_x] != '1')
		player->pos.x = move_x;
	if (map[(int)move_y][(int)player->pos.x] != '1')
		player->pos.y = move_y;
}

void	right_move(t_player *player, char **map, double rad)
{
	double	move_y;
	double	move_x;

	move_x = player->pos.x - (player->speed * sin(rad));
	move_y = player->pos.y + (player->speed * cos(rad));
	if (map[(int)player->pos.y][(int)move_x] != '1')
		player->pos.x = move_x;
	if (map[(int)move_y][(int)player->pos.x] != '1')
		player->pos.y = move_y;
}

void	forward_move(t_player *player, char **map, double rad)
{
	double	move_y;
	double	move_x;

	move_x = player->pos.x + (player->speed * cos(rad));
	move_y = player->pos.y + (player->speed * sin(rad));
	if (map[(int)player->pos.y][(int)move_x] != '1')
		player->pos.x = move_x;
	if (map[(int)move_y][(int)player->pos.x] != '1')
		player->pos.y = move_y;
}

void	backward_move(t_player *player, char **map, double rad)
{
	double	move_y;
	double	move_x;

	move_x = player->pos.x - (player->speed * cos(rad));
	move_y = player->pos.y - (player->speed * sin(rad));
	if (map[(int)player->pos.y][(int)move_x] != '1')
		player->pos.x = move_x;
	if (map[(int)move_y][(int)player->pos.x] != '1')
		player->pos.y = move_y;
}

void	move_player(int move, t_player *player, char **map, t_data *data)
{
	double	rad;

	rad = player->dir * PI_DIV_180;
	if (move == LEFT)
		left_move(player, map, rad);
	if (move == RIGHT)
		right_move(player, map, rad);
	if (move == FRONT)
		forward_move(player, map, rad);
	if (move == BACK)
		backward_move(player, map, rad);
	sort_segments(&player->pos, data->segments, data->nb_seg);
}
