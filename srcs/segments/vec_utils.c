/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:18:26 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/18 21:22:04 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	add_vec(const t_vec2 *vec1, const t_vec2 *vec2)
{
	t_vec2	res;

	res.x = vec1->x + vec2->x;
	res.y = vec1->y + vec2->y;
	return (res);
}

t_vec2	substract_vec(const t_vec2 *vec1, const t_vec2 *vec2)
{
	t_vec2	res;

	res.x = vec1->x - vec2->x;
	res.y = vec1->y - vec2->y;
	return (res);
}

t_vec2	scale_vec(const t_vec2 *vec, double nb)
{
	t_vec2	res;

	res.x = vec->x * nb;
	res.y = vec->y * nb;
	return (res);
}

double	dot_product(const t_vec2 *vec1, const t_vec2 *vec2)
{
	return ((vec1->x * vec2->x) + (vec1->y * vec2->y));
}

double	cross_product(const t_vec2 *vec1, const t_vec2 *vec2)
{
	return ((vec1->x * vec2->y) - (vec1->y * vec2->x));
}
