/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:06:57 by jrenau-v          #+#    #+#             */
/*   Updated: 2023/07/24 15:07:06 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_key_hook(int key, t_app *app)
{
	if (key == 53)
		fdf_exit_hook(app);
	else if (key == FDF_PLUS || key == FDF_MINUS || key == FDF_MORE
		|| key == FDF_LESS || key == FDF_INTRO || key == FDF_SPACE)
		fdf_zoom_event(app, key);
	if (key == FDF_Y || key == FDF_A || key == FDF_S || key == FDF_D
		|| key == FDF_Z || key == FDF_X || key == FDF_C)
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
	if (key == FDF_PLUS)
		app->scale.y += 20;
	if (key == FDF_MINUS)
		app->scale.y -= 20;
	if (key == FDF_MORE)
		app->scale.x += 20;
	if (key == FDF_LESS)
		app->scale.x -= 20;
	if (key == FDF_INTRO)
		app->scale.z += 20;
	if (key == FDF_SPACE)
		app->scale.z -= 20;
	return (0);
}

int	fdf_rotate_event(t_app *app, int key)
{
	if (key == FDF_A)
		app->rotation.z += app->td.z_rotate;
	if (key == FDF_Z)
		app->rotation.z -= app->td.z_rotate;
	if (key == FDF_S)
		app->rotation.x += app->td.x_rotate;
	if (key == FDF_X)
		app->rotation.x -= app->td.x_rotate;
	if (key == FDF_D)
		app->rotation.y += app->td.y_rotate;
	if (key == FDF_C)
		app->rotation.y -= app->td.y_rotate;
	if (key == FDF_Y)
		app->rotation.y -= app->td.y_rotate;
	return (0);
}

int	fdf_translate_event(t_app *app, int key)
{
	if (key == FDF_RIGHT)
		app->translation.x += 20;
	if (key == FDF_LEFT)
		app->translation.x -= 20;
	if (key == FDF_UP)
		app->translation.y -= 20;
	if (key == FDF_DOWN)
		app->translation.y += 20;
	return (0);
}
