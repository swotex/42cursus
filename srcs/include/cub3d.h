/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 03:40:50 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/06/09 16:37:16 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../libft/libft.h"
# define FALSE 0
# define TRUE 1

typedef struct s_var {
    void    *mlx;
    void    *win;
    char    **map;
    float   x;
    float   y;
}               t_var;

typedef struct s_map
{
    int no_fd;
    int so_fd;
    int we_fd;
    int ea_fd;
}           t_map;

typedef struct s_data
{
    t_map  *map;
}           t_data;

//parsing
int	parsing_handler(int argc, char **argv, t_map *map);
//utils
int	skip_set(char *str, char *set);

#endif
