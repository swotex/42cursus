/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:34:37 by njegat            #+#    #+#             */
/*   Updated: 2023/07/25 20:56:48 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../libft/libft.h"
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../MLX42/include/MLX42/MLX42_Int.h"
# include <math.h>
# define FALSE 0
# define TRUE 1
# define WIDTH 1620.0
# define HEIGHT 780.0
# define FOV 80.0
# define PI_DIV_180 0.0174532

enum e_card{
	N,
	S,
	E,
	W
};

enum e_move{
	FRONT,
	BACK,
	LEFT,
	RIGHT
};

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_inter
{
	double		dist;
	double		img_x;
	enum e_card	dir;
}			t_inter;

typedef struct s_ray
{
	t_vec2	pos;
	t_vec2	dir;
	double	rad;
}			t_ray;

typedef struct s_segment
{
	t_vec2		p1;
	t_vec2		p2;
	t_vec2		normal;
	double		dist;
	enum e_card	dir;
}			t_segment;

typedef struct s_player
{
	t_vec2	pos;
	double	speed;
	int		dir;
}			t_player;

typedef struct s_map
{
	mlx_texture_t	*texture[4];
	int32_t			f_color;
	int32_t			c_color;
	char			**plan;
}			t_map;

typedef struct s_data
{
	double		screen_dist;
	t_map		map;
	t_player	player;
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_segment	*segments;
	int			nb_seg;
}			t_data;

//parsing
void		parsing_handler(int argc, char **argv, t_data *data);
char		*get_textures(int fd, char *line, t_map *map);
int			get_cardinal(char *line);
int			is_duplicates(int cardinal, t_map *map);
char		*get_colors(int fd, char *line, t_map *map);
void		quit(t_map *map, int fd, char *line, int pflag);
void		rgb_to_hex(t_map *map, int *rgb, int flag);
void		init_rgb(int *rgb);
void		get_map(int fd, char *line, t_map *map);
void		check_map(t_map *map);
int			is_player(char c);
void		find_player(char **plan, t_player *player);
void		find_segments(t_data *data, char **map);
//parsing utils
void		release_all(t_map *map, int fd, char *line);
int			check_texture_ext(char *line);
int			is_flag_color(char *line);
size_t		array_len(char **arr);
//utils
int			skip_set(char *str, char *set);
char		**ft_strappend(char *add, char **in);
//game
void		launch_game(t_data *data);
//display
void		display(t_data *data);
//moves
void		move_player(int move, t_player *player, char **map, t_data *data);
//raycast
void		raycasting(const t_segment *segments, int nb_seg, t_player player,
				t_data *data);
//segment
t_segment	init_segment(t_vec2 vec1, t_vec2 vec2, enum e_card dir);
t_vec2		normalize_vec(const t_vec2 *vec);
t_vec2		move_point(const t_vec2 *pos, const t_vec2 *vec, double dist);
void		sort_segments(const t_vec2 *pos, t_segment *segments, int nb_seg);
//vec_utils
t_vec2		add_vec(const t_vec2 *vec1, const t_vec2 *vec2);
t_vec2		substract_vec(const t_vec2 *vec1, const t_vec2 *vec2);
t_vec2		scale_vec(const t_vec2 *vec, double nb);
double		dot_product(const t_vec2 *vec1, const t_vec2 *vec2);
double		cross_product(const t_vec2 *vec1, const t_vec2 *vec2);
//pixel
int32_t		get_pixel_texture(mlx_texture_t *texture, double img_x,
				double img_y);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b);
//draw
void		draw_wall(t_inter *inter, int px, double diff_rad, t_data *data);
void		draw_background(t_data *data, int32_t ceiling, int32_t floor);

#endif