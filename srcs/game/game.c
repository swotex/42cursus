/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:08:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/25 20:33:48 by tdhaussy         ###   ########.fr       */
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

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_player(FRONT, &data->player, data->map.plan, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_player(BACK, &data->player, data->map.plan, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_player(LEFT, &data->player, data->map.plan, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_player(RIGHT, &data->player, data->map.plan, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_player(LEFT, &data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_player(RIGHT, &data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		data->player.speed = 0.2;
	else
		data->player.speed = 0.1;
	display(data);
}

void	launch_game(t_data *data)
{
	data->screen_dist = (WIDTH / 2.0 * 1.5) / tan(FOV / 2.0);
	data->mlx = mlx_init(WIDTH, HEIGHT, "GET_CUBED", false);
	if (!data->mlx)
	{
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
	sort_segments(&data->player.pos, data->segments, data->nb_seg);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
