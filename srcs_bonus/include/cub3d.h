/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:34:37 by njegat            #+#    #+#             */
/*   Updated: 2023/07/30 19:25:04 by tdhaussy         ###   ########.fr       */
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
# define TITLE "GET_CUBED"
# define WIDTH 1620.0
# define HEIGHT 780.0
# define FOV 80.0
# define PI_DIV_180 0.0174532
# define MINI_BLOC 17

enum e_card{
	N,
	S,
	E,
	W,
	D
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
	int			seg_nb;
}			t_inter;

typedef struct s_ray
{
	t_vec2	pos;
	t_vec2	dir;
	double	rad;
}			t_ray;

typedef struct s_segment
{
	int			id;
	t_vec2		p1;
	t_vec2		p2;
	t_vec2		normal;
	double		dist;
	enum e_card	dir;
	double		limit;
	double		limit_incr;
}			t_segment;

typedef struct s_door
{
	t_vec2	pos;
	int		id_seg[4];
	int		nb_seg;
}			t_door;

typedef struct s_player
{
	t_vec2	pos;
	double	speed;
	int		dir;
}			t_player;

typedef struct s_map
{
	mlx_texture_t	*texture[5];
	int32_t			f_color;
	int32_t			c_color;
	int				radius;
	t_vec2			center_pos;
	char			**plan;
	int				display;
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
	t_door		*doors;
	int			nb_door;
}			t_data;

//parsing
void		parsing_handler(int argc, char **argv, t_data *data);
char		*get_textures(int fd, char *line, t_map *map);
void		open_door_txt(char *path, t_map *map);
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
int			add_segment(t_data *data, t_vec2 vec1, t_vec2 vec2,
				enum e_card dir);
void		find_doors(t_data *data, char **map);
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
//doors_loop
void		update_doors(t_data *data, t_door *doors, char **map);
void		unstuck_player(t_data *data, t_door *doors, t_player player);
//display
void		display(t_data *data);
void		display_map(t_data *data, char **map, int size);
//moves
void		move_player(int move, t_player *player, char **map, t_data *data);
//rotation
void		rotate_player(int move, t_player *player);
void		mouse_rotate(t_data *data);
//raycast
void		raycasting(const t_segment *segments, int nb_seg, t_player player,
				t_data *data);
void		init_inter(t_inter *inter);
t_inter		intersect_segs(const t_segment *segments, int nb_seg,
				const t_ray *ray);
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
int32_t		map_color(char pos);
//draw
void		draw_wall(t_inter *inter, int px, double diff_rad, t_data *data);
void		draw_background(t_data *data, int32_t ceiling, int32_t floor);
void		draw_mini(t_map map, mlx_image_t *image, t_player player);
void		draw_segments(t_segment *segments, int size, t_data *data);
//draw_utils
void		fill_bloc(const t_vec2 *pos, t_map map, int32_t color,
				mlx_image_t *image);
void		draw_line(t_segment segment, int size, t_data *data, int32_t color);
void		add_player(const t_vec2 *pos, int dir, int size,
				mlx_image_t *image);
//interact
void		interact(t_segment *segments, int nb_seg, t_player player,
				t_data *data);
t_inter		intersect_door(const t_segment *segments, int nb_seg,
				const t_ray *ray);
void		animate_doors(t_segment *segments, int nb_seg);

#endif