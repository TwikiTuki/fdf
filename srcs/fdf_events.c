#include "fdf.h"

int	fdf_key_hook(int key, t_app *app)
{
	if (key == FDF_ESC)
		fdf_exit_hook(app);
	else if (key == FDF_ALT || key == FDF_SPACE || key == FDF_SHIFT
		|| key == FDF_CTRL || key == FDF_Z || key == FDF_X)
		fdf_zoom_event(app, key);
	if (key == FDF_Q || key == FDF_W || key == FDF_E
		|| key == FDF_A || key == FDF_S || key == FDF_D)
		fdf_rotate_event(app, key);
	if (key == FDF_LEFT || key == FDF_RIGHT || key == FDF_UP || key == FDF_DOWN)
		fdf_translate_event(app, key);
	mlx_destroy_image(app->mlx_ptr, app->img_ptr);
	mlx_clear_window(app->mlx_ptr, app->win_ptr);
	fdf_transform(&app->transformed, &app->original, *app);
	app->img_ptr = mlx_new_image(app->mlx_ptr, FDF_WIN_WIDTH, FDF_WIN_HEIGHT);
	app->img_dta = mlx_get_data_addr(app->img_ptr, &app->bits_per_pixel,
			&app->size_line, &app->endian); 
	fdf_prnt_mtrx(*app);
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
	return (0);
}

int	fdf_exit_hook(t_app *app)
{
	fdf_abort_matrix(&app->original);
	fdf_abort_matrix(&app->transformed);
	mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	mlx_destroy_image(app->mlx_ptr, app->img_ptr);
	exit(0);
}

int	fdf_zoom_event(t_app *app, int key)
{
	if (key == FDF_SHIFT)
		app->scale.y += 20;
	if (key == FDF_CTRL)
		app->scale.y -= 20;
	if (key == FDF_X)
		app->scale.x += 20;
	if (key == FDF_Z)
		app->scale.x -= 20;
	if (key == FDF_SPACE)
		app->scale.z += 20;
	if (key == FDF_ALT)
		app->scale.z -= 20;
	return (0);
}

int	fdf_rotate_event(t_app *app, int key)
{
	if (key == FDF_E)
		app->rotation.z += app->td.z_rotate;
	if (key == FDF_Q)
		app->rotation.z -= app->td.z_rotate;
	if (key == FDF_W)
		app->rotation.x += app->td.x_rotate;
	if (key == FDF_S)
		app->rotation.x -= app->td.x_rotate;
	if (key == FDF_A)
		app->rotation.y += app->td.y_rotate;
	if (key == FDF_D)
		app->rotation.y -= app->td.y_rotate;
	return (0);
}

int	fdf_translate_event(t_app *app, int key)
{
	if (key == FDF_RIGHT)
		app->translation.x -= 20;
	if (key == FDF_LEFT)
		app->translation.x += 20;
	if (key == FDF_UP)
		app->translation.y += 20;
	if (key == FDF_DOWN)
		app->translation.y -= 20;
	return (0);
}
