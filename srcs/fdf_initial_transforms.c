/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initial_transforms.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:49:59 by jrenau-v          #+#    #+#             */
/*   Updated: 2023/07/23 16:35:03 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_initial_scale(t_app *app)
{
	ft_printf("initial scale: ");
	app->scale.x = FDF_WIN_WIDTH - FDF_WIN_HORITZONTAL_PADDING * 2;
	app->scale.y = FDF_WIN_HEIGHT - FDF_WIN_VERTICAL_PADDING * 2;
	fdf_print_pnt(app->scale);
	if (app->original.nc > 1)
		app->scale.x = app->scale.x / (app->original.nc - 1) / 2;
	else
		app->scale.x = 1;
	if (app->original.nr > 1)
		app->scale.y = app->scale.y / (app->original.nr - 1) / 2;
	else
		app->scale.y = 1;
	app->scale.z = 9;
	ft_printf("\n");
}

void	fdf_initial_translation(t_app *app)
{
	app->translation.x = 0;
	app->translation.y = 0;
	return ;
	app->translation.x = FDF_WIN_HORITZONTAL_PADDING;
	app->translation.y = FDF_WIN_VERTICAL_PADDING;
	app->translation.x = app->original.nc * app->scale.x / 2
		+ FDF_WIN_HORITZONTAL_PADDING; 
	app->translation.y = app->original.nr * app->scale.y / 2
		+ FDF_WIN_VERTICAL_PADDING; 
	app->translation.z = 0; 
}
//
