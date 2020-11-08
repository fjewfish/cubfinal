/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header_v2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:55:51 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 21:26:30 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_V2_H
# define MAIN_HEADER_V2_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# define MIN_RES_X 300
# define MIN_RES_Y 300
# define INDEX aio->ray.i + aio->img.coef_dylib * y_coef
# define RES_Y aio->res.map_y
# define RES_X aio->res.map_x
# define COEF aio->img.coef_dylib
# define POS_Y (int)floor(aio->plr.pos_y)
# define POS_X (int)floor(aio->plr.pos_x)
# define BLUE 0x000000FF
# define PURPLE 0x00FF00FF
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLACK 0x00000000
# define MAX 999999999999
# define TEX aio->res.tex
# define F 3
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SPEED 0.2
# define TURN 0.08

typedef struct		s_minimap
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				delta_x;
	int				delta_y;
	int				error;
	int				delta_err;
	int				error2;
	int				delta_err2;
	int				diry;
	int				diry2;
}					t_minimap;

typedef struct		s_robot_checker
{
	int				x;
	int				y;
	int				start_x;
	int				start_y;
}					t_robot_checker;

typedef struct		s_parse_error
{
	int				map_trigger;
	int				map_empty_line;
	int				settings;
	int				player;
}					t_parse_error;

typedef struct		s_mapmod
{
	int				on_off;
	double			first_hit_x;
	double			first_hit_y;
	double			last_hit_x;
	double			last_hit_y;
}					t_mapmod;

typedef struct		s_mlx
{
	void			*ptr;
}					t_mlx;

typedef struct		s_win
{
	void			*ptr;
}					t_win;

typedef struct		s_img
{
	void			*ptr;
	unsigned int	*adr;
	void			*ptr_m;
	unsigned int	*adr_m;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				bpp_m;
	int				ll_m;
	int				e_m;
	int				coef_dylib;
}					t_img;

typedef struct		s_map
{
	int				cut_left;
	int				cut_right;
	char			**map;
	int				width;
	int				height;
	int				sprite_count;
	t_list			*list;
}					t_map;

typedef struct		s_tex
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*sprite;
	unsigned int	*no;
	unsigned int	*so;
	unsigned int	*ea;
	unsigned int	*we;
	unsigned int	*sp;
	unsigned int	ce;
	unsigned int	fl;
	int				r;
	int				g;
	int				b;
}					t_tex;

typedef struct		s_res
{
	int				map_x;
	int				map_y;
	int				display_x;
	int				display_y;
	int				tex;
	int				if_map;
}					t_res;

typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			pov;
}					t_player;

typedef struct		s_ray
{
	double			x;
	double			y;
	int				i;
	double			ver;
	double			hor;
	double			tan_v;
	double			tan_h;
	double			*sin;
	double			*cos;
	double			*fish;
}					t_ray;

typedef struct		s_hit
{
	double			height;
	double			x;
	double			y;
	double			d;
	double			x_v;
	double			y_v;
	double			x_h;
	double			y_h;
	double			dist_ver;
	double			dist_hor;
	double			*distance;
}					t_hit;

typedef struct		s_key
{
	int				e;
	int				w;
	int				a;
	int				s;
	int				d;
	int				l;
	int				r;
	int				h;
	int				x;
}					t_key;

typedef struct		s_spr
{
	double			x;
	double			y;
	double			d;
}					t_spr;

typedef struct		s_aio
{
	t_parse_error	parse_error;
	t_mapmod		mapmod;
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_tex			tex;
	t_res			res;
	t_map			map;
	t_player		plr;
	t_ray			ray;
	t_hit			hit;
	t_key			key;
	t_spr			*spr;
}					t_aio;

/*
** 	A_MAIN
*/
int					ft_cub(char *cub, int screenshot);
void				ft_init_img_and_win(t_aio *aio);
/*
** 	B_INITIALIZATION
*/
void				ft_initialization(t_aio *aio);
void				ft_initialization_2(t_aio *aio);
void				ft_initialization_3(t_aio *aio);
void				ft_initialization_4(t_aio *aio);
/*
** 	C_PARSE
*/
int					ft_parse(t_aio *aio, char *cub);
void				ft_rnswesfc(t_aio *aio, char *line);
void				ft_makemap_list(t_aio *aio, char *line);
int					ft_map_parse(t_aio *aio);
int					ft_write_and_cut(t_aio *aio, int *cut_left, int *cut_right);
void				ft_write_and_cut_2(t_aio *aio, t_list *tmp, int i);
int					ft_write_and_cut_check(char check);
void				ft_gnl_parse(t_aio *aio, char *line);
void				ft_rnswesfc_2(t_aio *aio, char *line, int *i);
int					ft_parse_errors(t_aio *aio);
void				ft_position(t_aio *aio);
int					ft_skip_only_space_zero_up(char *line);
int					ft_skip_only_space_zero_left(char *line);
int					ft_skip_only_space_zero_right(char *line);
int					ft_walls(t_aio *aio);
char				**ft_init_protected_map(t_aio *aio, char change);
char				**ft_init_protected_map_2(t_aio *aio, char change);
int					ft_recursive_paint_algorithm(int y, int x, char **map_p,
												t_aio *aio);
int					ft_check_map_potected(char **map_p, t_aio *aio);
void				ft_print_map_p(char **map_p);
int					ft_skip_spases(char *line, int *i);
int					ft_atoi_i(char *line, int *i);
int					ft_check_file_ext(char *file, char *ext);
int					ft_resolution(t_aio *aio, char *line, int *i);
int					ft_texture(t_aio *aio, unsigned int **adr,
								char *line, int *i);
int					ft_rgb(unsigned int *color, char *line, int *i, t_aio *aio);
void				ft_recursive_while(char **map_p, t_aio *aio);
/*
** 	D_PUT_IMAGE
*/
void				ft_pre_put_image(t_aio *aio);
int					ft_main_put_image(t_aio *aio);
void				ft_create_img(t_aio *aio);
void				ft_column(t_aio *aio, int size);
int					ft_column_init(t_aio *aio, int size, unsigned int *color,
						int *start);
unsigned int		ft_pixel(t_aio *aio, double i);
void				ft_tangent_ray(t_aio *aio);
void				ft_ray_direction(t_aio *aio);
void				ft_vertical(t_aio *aio);
void				ft_horizontal(t_aio *aio);
int					free_map(char **map_p);
void				ft_fisheye(t_aio *aio, int i);
/*
** 	E_HOOKS
*/
int					ft_set(t_aio *aio, int key, int set);
int					ft_press(int key, t_aio *aio);
int					ft_release(int key, t_aio *aio);
int					ft_key(t_aio *aio);
void				ft_move(t_aio *aio, double coeff);
void				ft_strafe(t_aio *aio, double coeff);
void				ft_rotate(t_aio *aio, double c);
void				ft_key_w(t_aio *aio);
void				ft_key_s(t_aio *aio);
void				ft_key_d(t_aio *aio);
void				ft_key_a(t_aio *aio);
void				ft_key_r(t_aio *aio);
void				ft_key_l(t_aio *aio);
/*
** 	F_MAPS
*/
void				ft_map_mode(t_aio *aio);
void				ft_map_mini(t_aio *aio);
int					ft_init_scale(t_aio *aio);
void				ft_map_pixel_put(t_aio *aio, int scale);
void				pixel_put_white(t_aio *aio, int x, int y, int scale);
void				pixel_put_red(t_aio *aio, int x, int y, int scale);
void				pixel_put_plr(t_aio *aio, double x, double y, int scale);
void				pixel_put_ray(t_aio *aio, double x, double y, int scale);
void				while_1(t_minimap mm, t_aio *aio);
void				while_2(t_minimap mm, t_aio *aio);
t_minimap			ft_mm_init_right(t_aio *aio, double x, double y, int scale);
t_minimap			ft_mm_init_left(t_aio *aio, double x, double y, int scale);
/*
** 	G_SPRITE
*/
int					ft_slist(t_aio *aio);
void				ft_sprite(t_aio *aio);
void				ft_sorder(t_aio *aio);
void				ft_slocate(t_aio *aio, double dirx,
								double diry, double dist);
void				ft_sdraw(t_aio *aio, int loc, double dist);
unsigned int		ft_spixel(t_aio *aio, int index, unsigned int col);
void				ft_put_sprite(t_aio *aio, int loc, double dist,
									double size);
/*
** 	H_SCREENSHOT
*/
void				ft_bdata(t_aio *aio, int fd);
void				ft_binfo(t_aio *aio, int fd);
void				ft_bfile(t_aio *aio, int fd);
int					ft_bmp_save(t_aio *aio);
/*
** 	I_EXIT_AND_ERRORS
*/
int					ft_close(t_aio *aio, int win);
int					ft_error_number(int error);
void				ft_error_number_2(int error);
int					ft_close2(t_aio *aio, int win);
/*
** 	USEFUL_FUN
*/
void				ft_print_parse(t_aio *aio);
void				ft_print_parse_2(t_aio *aio);
void				ft_print_parse_3(t_aio *aio);

#endif
