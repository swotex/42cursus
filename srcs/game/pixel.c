/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:41:22 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/25 03:52:50 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

int	get_pixel_pos(mlx_texture_t *texture, double x, double y)
{
	int	pos;
	int	img_x;
	int	img_y;

	img_x = x * (texture->width - 1);
	img_y = y * (texture->height - 1);
	pos = texture->width * img_y + img_x;
	pos *= texture->bytes_per_pixel;
	return (pos);
}

int32_t	get_pixel_texture(mlx_texture_t *texture, double img_x, double img_y)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	pos;

	pos = get_pixel_pos(texture, img_x, img_y);
	r = texture->pixels[pos];
	g = texture->pixels[pos + 1];
	b = texture->pixels[pos + 2];
	a = texture->pixels[pos + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}
