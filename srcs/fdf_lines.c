/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:43:44 by jrenau-v          #+#    #+#             */
/*   Updated: 2023/07/23 16:27:15 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_swap_p(t_point *p1, t_point *p2)
{
	t_point	aux_p;

	aux_p = *p1;
	*p1 = *p2;
	*p2 = aux_p;
}

void	fdf_put_pixel(void *img_ptr, unsigned int x, unsigned int y, int color)
{
	char	*img_dta;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		bytes_per_pixel;

	x += FDF_WIN_WIDTH / 2; 
	y += FDF_WIN_HEIGHT / 2; 
	if (x >= FDF_WIN_WIDTH)
		return ;
	if (y >= FDF_WIN_HEIGHT)
		return ;
	img_dta = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	bytes_per_pixel = bits_per_pixel / 8;
	if (bytes_per_pixel != 4)
		ft_printf("The bytes per pixel is not 4 !!!!!!!!\n");
	ft_memcpy(img_dta + ((x * bytes_per_pixel) % size_line + y * size_line),
		&color, sizeof(int));
}

void	fdf_draw_on_same_x(t_app *app, t_point p1, t_point p2, int clr)
{
	t_point	lst_p;	
	t_point	cur_p;	

	if (p1.y > p2.y)
		fdf_swap_p(&p1, &p2);
	lst_p = p1;
	cur_p = p1;
	while (cur_p.y <= p2.y)
	{
		fdf_put_pixel(app->img_ptr, p1.x, cur_p.y, clr);
		cur_p.y++;
	}
}

void	fdf_draw_line(t_app *app, t_point p1, t_point p2, int clr)
{
	float	d;
	t_point	lst_p;	
	t_point	cur_p;	

	if (p1.x == p2.x)
		return (fdf_draw_on_same_x(app, p1, p2, clr));
	if (p1.x > p2.x)
		fdf_swap_p(&p1, &p2);
	lst_p = p1;
	cur_p = p1;
	d = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
	while (cur_p.x <= p2.x)
	{
		fdf_put_pixel(app->img_ptr, cur_p.x, cur_p.y, clr);
		if (lst_p.y != cur_p.y
			&& (lst_p.y + 1 != cur_p.y && lst_p.y != cur_p.y + 1))
		{
			lst_p.x = cur_p.x;
			lst_p.y += ((d > 0) * 2) - 1;
			fdf_draw_line(app, lst_p, cur_p, clr);
		}
		lst_p = cur_p;
		cur_p.x++;
		cur_p.y = p1.y + (cur_p.x - p1.x) * d;
	}
}
