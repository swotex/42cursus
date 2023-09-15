/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 03:12:27 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/30 19:25:11 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map_bloc(t_vec2 *print, int size, t_data *data,
			int32_t color)
{
	int	x;
	int	y;

	y = print->y - size / 2;
	while (y <= print->y + size / 2)
	{
		x = print->x - size / 2;
		while (x <= print->x + size / 2)
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
				mlx_put_pixel(data->image, x, y, color);
			x++;
		}
		y++;
	}
	print->x += size;
}

void	map_player_pos(t_vec2 *print, t_vec2 pos, char **map, int size)
{
	print->x = WIDTH / 2 - (ft_strlen(map[0]) / 2 * size)
		+ pos.x * size - size / 2;
	print->y = HEIGHT / 2 - (array_len(map) / 2 * size)
		+ pos.y * size - size / 2;
}

void	display_map(t_data *data, char **map, int size)
{
	int		x;
	int		y;
	int32_t	color;
	t_vec2	print;

	print.y = HEIGHT / 2 - (array_len(map) / 2 * size);
	y = 0;
	while (map[y])
	{
		x = 0;
		print.x = WIDTH / 2 - (ft_strlen(map[0]) / 2 * size);
		while (map[y][x])
		{
			color = map_color(map[y][x]);
			fill_map_bloc(&print, size, data, color);
			x++;
		}
		print.y += size;
		y++;
	}
	map_player_pos(&print, data->player.pos, map, size);
	draw_segments(data->segments, size, data);
	add_player(&print, data->player.dir, size / 2, data->image);
}

void	display_fps(mlx_t *mlx)
{
	static double	time_passed = 0;
	static int		frames = 0;
	char			*tmp;
	char			*title;

	frames++;
	time_passed += mlx->delta_time;
	if (time_passed < 1.0)
		return ;
	time_passed -= 1.0;
	tmp = ft_itoa(frames);
	frames = 0;
	title = ft_strjoin(TITLE, " | ");
	if (!tmp || !title)
		return ;
	title = ft_strjoin_free_first(title, tmp);
	title = ft_strjoin_free_first(title, " FPS");
	free(tmp);
	mlx_set_window_title(mlx, title);
	free(title);
}

void	display(t_data *data)
{
	animate_doors(data->segments, data->nb_seg);
	display_fps(data->mlx);
	if (data->image)
		mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
	draw_background(data, data->map.c_color, data->map.f_color);
	raycasting(data->segments, data->nb_seg, data->player, data);
	draw_mini(data->map, data->image, data->player);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
}
