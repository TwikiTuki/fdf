#include <math.h>
#include "fdf.h"

static int	fdf_start_app(t_app *app, char *file);
void		fdf_transform(t_matrix *trans, t_matrix *orig, t_app app);
void		fdf_prnt_mtrx(t_app app );
t_point		fdf_rotate_point(t_point point, t_point angle);

int	main(int argc, char **argv)
{
	t_app	app;

	if (argc < 2)
	{
		ft_printf("no file privided\n");
		exit (0);
	}
	if (!fdf_check_extension(argv[1], ".fdf"))
	{
		ft_printf("invalid file extension\n");
		exit (0);
	}
	ft_printf("Starting app\n");
	if (!fdf_start_app(&app, argv[1]))
		exit (0);
	ft_printf("Transforming\n");
	fdf_transform(&app.transformed, &app.original, app);
	ft_printf("Printing matrix to image\n");
	fdf_prnt_mtrx(app);
	ft_printf("Putting image to window\n");
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	ft_printf("Loopping\n");
	mlx_loop(app.mlx_ptr);
}

static int	fdf_start_app(t_app *app, char *file)
{
	app->original = fdf_matrix_init(file);
	if (!app->original.nr || !app->original.nc)
		return (0);
	app->rotation = fdf_set_point(32, 0, 45);
	fdf_initial_scale(app);
	fdf_initial_translation(app);
	fdf_calloc_matrix_mem(&app->transformed,
		fdf_set_point(app->original.nc, app->original.nr, 0));
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr,
			FDF_WIN_WIDTH, FDF_WIN_HEIGHT, "helllow");
	mlx_hook(app->win_ptr, 2, 1L << 0, fdf_key_hook, app);
	mlx_hook(app->win_ptr, 17, 1L << 17, fdf_exit_hook, app);
	app->img_ptr = mlx_new_image(app->mlx_ptr, FDF_WIN_WIDTH, FDF_WIN_HEIGHT);
	app->img_dta = mlx_get_data_addr(app->img_ptr,
			&app->bits_per_pixel, &app->size_line, &app->endian); 
	app->count = 0;
	app->td.x_trans = X_TRANS; 
	app->td.y_trans = Y_TRANS;
	app->td.x_sclae = X_SCALE;
	app->td.y_sclae = Y_SCALE;
	app->td.x_rotate = X_ROTATE;
	app->td.y_rotate = Y_ROTATE;
	app->td.z_rotate = Z_ROTATE;
	return (1);
}

void	fdf_transform(t_matrix *trans, t_matrix *orig, t_app app)
{
	int	i;
	int	j;

	trans->nr = orig->nr;
	trans->nc = orig->nc;
	i = -1;
	while (++i < trans->nr)
	{
		j = -1;
		while (++j < trans->nc)
		{
			trans->points[i][j].x = orig->points[i][j].x * app.scale.x;
			trans->points[i][j].y = orig->points[i][j].y * app.scale.y;
			trans->points[i][j].z = orig->points[i][j].z * app.scale.z;
			trans->points[i][j] = fdf_rotate_point(trans->points[i][j],
					app.rotation);
			trans->points[i][j].x = trans->points[i][j].x + app.translation.x;
			trans->points[i][j].y = trans->points[i][j].y + app.translation.y;
			trans->points[i][j].z = trans->points[i][j].z + app.translation.z;
		}
	}
}

t_point	fdf_rotate_point(t_point point, t_point angle)
{
	t_point	p;
	double	aux;
	double	rad;
	t_point	result;

	p.x = point.x;
	p.y = point.y;
	p.z = point.z;
	aux = p.x ;
	rad = M_PI * 2 * angle.z / 360;
	p.x = p.x * cos(rad) - p.y * sin(rad);
	p.y = p.y * cos(rad) + aux * sin(rad);
	aux = p.x ;
	rad = M_PI * 2 * angle.y / 360;
	p.x = p.x * cos(rad) + p.z * sin(rad);
	p.z = p.z * cos(rad) - aux * sin(rad);
	aux = p.y;
	rad = M_PI * 2 * angle.x / 360;
	p.y = p.y * cos(rad) - p.z * sin(rad);
	p.z = p.z * cos(rad) + aux * sin(rad);
	result = fdf_set_point(p.x, p.y, p.z);
	return (result);
}

void	fdf_prnt_mtrx(t_app app)
{
	int		row;
	int		col;
	t_point	**pnts;

	pnts = app.transformed.points;
	row = 0;
	while (row < app.transformed.nr)
	{
		col = 0;
		while (col < app.transformed.nc)
		{
			if (col + 1 < app.transformed.nc)
			{
				fdf_draw_line(&app, pnts[row][col], pnts[row][col + 1],
					fdf_mk_color(0, 255, 255, 255));
			}
			if (row + 1 < app.transformed.nr)
			{
				fdf_draw_line(&app, pnts[row][col], pnts[row + 1][col],
					fdf_mk_color(0, 255, 255, 255));
			}
			col++;
		}
		row++;
	}
}

//TODO
//Norminette
//fdf.h
//
//Carregar 
//Reference matrix
//Transformed matrix
//
//Rortate
//Transalte
//Scale
//
//Print content
//
//Manage user interaction
//
