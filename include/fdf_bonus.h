/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:56:03 by njegat            #+#    #+#             */
/*   Updated: 2023/01/31 07:49:38 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# define WHITE 0x00FFFFFF

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_dda {
	float	dx;
	float	dy;
	int		steps;
	float	x_increment;
	float	y_increment;
}				t_dda;

typedef struct s_matrix {
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}				t_matrix;

typedef struct s_data {
	int			matrix_x;
	int			matrix_y;
	int			space;
	int			pos_x;
	int			pos_y;
	int			offset_z;
	double		origin_x;
	double		origin_y;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	int			set_color;
	t_matrix	**matrix;
}				t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int		screen_x;
	int		screen_y;
	t_image	img;
	t_data	data;
	t_dda	dda;
}				t_mlx;

void			ft_hooks_handler(t_mlx *mlx);
void			ft_double_free(char **array);
int				ft_file_handler(char *file_name, t_mlx *mlx);
int				ft_exit(t_mlx *mlx);
int				ft_nb_digit(char *str);
int				ft_arraylen(char **array);
void			ft_free_matrix(t_data *data);
int				ft_matrix_handler(char **array, t_mlx *mlx);
void			ft_set_matrix_origin(t_data *data);
void			ft_print_matrix(t_mlx *mlx);
void			ft_set_pos_matrix(t_data *data);
void			ft_clear(t_mlx *mlx);
void			ft_zoom(t_data *data);
void			ft_set_origin_of_matrix(t_data *data);
void			ft_make_spin(t_mlx *mlx);
void			ft_init_data(t_mlx *mlx);
void			ft_display_legend(t_mlx *mlx);
unsigned int	ft_color_handler(t_data *data, int i, int j);
int				ft_found_color(char *str);
unsigned int	ft_get_color(char *str);
void			ft_dda(t_matrix *pt1, t_matrix *pt2, t_mlx *mlx, int color);
int				ft_rotate_hook(int keycode, t_mlx *mlx);
int				ft_up_down_top(int keycode, t_mlx *mlx);
int				ft_scroll(int keycode, int x, int y, t_mlx *mlx);
int				ft_shift(int keycode, t_mlx *mlx);

#endif
