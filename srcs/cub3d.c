/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 03:45:49 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/06/09 16:41:36 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map; // <--- faut init les fd a -1


	parsing_handler(argc, argv, &map);
	data.map = &map;
	return (0);
}
