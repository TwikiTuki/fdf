/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:25:16 by jrenau-v          #+#    #+#             */
/*   Updated: 2023/07/23 14:04:53 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef FDF_WIN_WIDTH
#  define FDF_WIN_WIDTH 2048
# endif
# ifndef FDF_WIN_HEIGHT
#  define FDF_WIN_HEIGHT	1024
# endif
# ifndef FDF_WIN_HORITZONTAL_PADDING
#  define FDF_WIN_HORITZONTAL_PADDING 0
# endif
# ifndef FDF_WIN_VERTICAL_PADDING
#  define FDF_WIN_VERTICAL_PADDING 0
# endif

# include "mlx.h"
# include "libft.h"
# include <stdio.h> //
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define FDF_A 0
# define FDF_S 1
# define FDF_D 2
# define FDF_Z 6
# define FDF_X 7
# define FDF_C 8
# define FDF_Y 16
# define FDF_PLUS 69
# define FDF_MINUS 78
# define FDF_LESS 43
# define FDF_MORE 47
# define FDF_INTRO 76
# define FDF_SPACE 49

# define FDF_LEFT 123
# define FDF_UP 126
# define FDF_RIGHT 124
# define FDF_DOWN 125

# define X_TRANS 20
# define Y_TRANS 20

# define X_SCALE 20
# define Y_SCALE 20

# define X_ROTATE 5
# define Y_ROTATE 5
# define Z_ROTATE 5

typedef struct point_s{
	int		x;
	int		y;
	int		z;
	int		color;
	char	fixed_color;
}				t_point;

typedef struct matrix_s{
	int			nr;
	int			nc;
	t_point		**points;
}				t_matrix;

typedef struct transform_diferentials_s
{
	int	x_trans;
	int	y_trans;

	int	x_sclae;
	int	y_sclae;

	int	x_rotate;
	int	y_rotate;
	int	z_rotate;
}				t_transform_diferentials;

typedef struct app_s
{
	void						*mlx_ptr;
	void						*win_ptr;
	void						*img_ptr;
	int							bits_per_pixel;
	int							size_line;
	int							endian;
	char						*img_dta;
	t_matrix					original;
	t_matrix					transformed;
	t_point						translation;
	t_point						scale;
	t_point						rotation;
	int							count;
	t_transform_diferentials	td;
}				t_app;

/* fdf.c */
void		looper(void *args);
void		fdf_prnt_mtrx(t_app app );
void		fdf_transform(t_matrix *trans, t_matrix *orig, t_app app);

/* fdf_lines.c */
void		fdf_swap_p(t_point *p1, t_point *p2);
void		fdf_put_pixel(void *img_ptr, unsigned int x,
				unsigned int y, int color);
void		fdf_draw_line(t_app *app, t_point p1, t_point p2, int clr);
void		fdf_draw_on_same_x(t_app *app, t_point p1, t_point p2, int clr);

/* fdf_linew_on_window.c */
void		fdf_draw_vertical(t_app *app, int x, int clr);
void		fdf_draw_horitzontal(t_app *app, int x, int clr);
void		fdf_draw_line_on_window(t_app *app,
				t_point p1, t_point p2, int clr);

/* fdf_points.c */
int			fdf_mk_color(int transparency, int red, int green, int blue);
void		fdf_print_pnt(t_point p);
t_point		fdf_set_point(int x, int y, int z);
void		fdf_swap_p(t_point *p1, t_point *p2);
void		fdf_load_point_color(t_point *p, char *color);//

void		fdf_print_matrix(t_matrix matrix);

/* fdf_matrices */
int			fdf_calloc_matrix_mem(t_matrix *matrix, t_point	dims);
t_matrix	*fdf_abort_matrix(t_matrix *matrix);
t_matrix	fdf_matrix_init(char *file);

/* fdf_initial_scale */
void		fdf_initial_scale(t_app *app);
void		fdf_initial_translation(t_app *app);

/* fdf_events.c */
int			fdf_key_hook(int key_code, t_app *app);
int			fdf_exit_hook(t_app *app);
int			fdf_exit_hook(t_app *app);
int			fdf_zoom_event(t_app *app, int key);
int			fdf_rotate_event(t_app *app, int key);
int			fdf_translate_event(t_app *app, int key);
/* fdf_utils.c */
/*static int	get_cols_from_line(char *line);*/
t_point		get_dims_from_file(char*file);
void		*free_matrix(void**list);
int			fdf_hex_int_atoi(char*str, char *base);
int			fdf_check_extension(char*file, char *ext);
#endif
