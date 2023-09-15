/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:08:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/30 20:36:53 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	interaction_loop(t_data *data)
{
	static int	e_press = FALSE;

	if (e_press == FALSE && mlx_is_key_down(data->mlx, MLX_KEY_E))
	{
		e_press = TRUE;
		interact(data->segments, data->nb_seg, data->player, data);
	}
	else if (!mlx_is_key_down(data->mlx, MLX_KEY_E) && e_press == TRUE)
		e_press = FALSE;
}

void	move_hook(t_data *data)
{
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
	interaction_loop(data);
	unstuck_player(data, data->doors, data->player);
	update_doors(data, data->doors, data->map.plan);
	mouse_rotate(data);
}

void	ft_hook(void *param)
{
	t_data		*data;
	static int	m_press = FALSE;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (m_press == FALSE && mlx_is_key_down(data->mlx, MLX_KEY_M))
	{
		m_press = TRUE;
		if (!data->map.display)
		{
			display_map(data, data->map.plan,
				fmin(WIDTH / ft_strlen(data->map.plan[0]),
					HEIGHT / array_len(data->map.plan)));
			data->map.display = TRUE;
		}
		else
			data->map.display = FALSE;
	}
	else if (!mlx_is_key_down(data->mlx, MLX_KEY_M))
		m_press = FALSE;
	if (data->map.display)
		return ;
	move_hook(data);
	display(data);
}

void	launch_game(t_data *data)
{
	data->screen_dist = (WIDTH / 2.0 * 1.5) / tan(FOV / 2.0);
	data->mlx = mlx_init(WIDTH, HEIGHT, TITLE, false);
	if (!data->mlx)
	{
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
	sort_segments(&data->player.pos, data->segments, data->nb_seg);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
