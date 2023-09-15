/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:23:53 by njegat            #+#    #+#             */
/*   Updated: 2023/07/30 20:32:12 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "errors.h"

size_t	array_len(char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (i);
	while (arr[i] != NULL)
		i++;
	return (i);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

void	release_map(t_map *map)
{
	if (map->texture[N])
		mlx_delete_texture(map->texture[N]);
	if (map->texture[S])
		mlx_delete_texture(map->texture[S]);
	if (map->texture[E])
		mlx_delete_texture(map->texture[E]);
	if (map->texture[W])
		mlx_delete_texture(map->texture[W]);
	if (map->plan)
		ft_free_tab(map->plan);
}

void	check_errors_map(t_map *map, size_t i, size_t j, size_t arr_len)
{
	if (i == 0 || j == 0 || i == arr_len || j == ft_strlen(map->plan[i]) - 1)
	{
		release_map(map);
		exit_error_parsing(MOPEN, "border not closed");
	}
	else if (map->plan[i][j + 1] == ' ')
	{
		release_map(map);
		exit_error_parsing(MOPEN, "border not closed");
	}
	else if (map->plan[i][j - 1] == ' ')
	{
		release_map(map);
		exit_error_parsing(MOPEN, "border not closed");
	}
	else if (map->plan[i + 1][j] == ' ')
	{
		release_map(map);
		exit_error_parsing(MOPEN, "border not closed");
	}
	else if (map->plan[i - 1][j] == ' ')
	{
		release_map(map);
		exit_error_parsing(MOPEN, "border not closed");
	}
}

void	check_map(t_map *map)
{
	size_t	i;
	size_t	j;
	int		nbplayer;

	i = 0;
	nbplayer = 0;
	while (map->plan[i])
	{
		j = 0;
		while (map->plan[i][j])
		{
			if (is_player(map->plan[i][j]) == TRUE)
				nbplayer++;
			if (map->plan[i][j] == '0' || is_player(map->plan[i][j]))
				check_errors_map(map, i, j, array_len(map->plan) - 1);
			j++;
		}
		i++;
	}
	if (nbplayer != 1)
	{
		release_map(map);
		exit_error_parsing(MOPEN, "invalid number of player.");
	}
}
