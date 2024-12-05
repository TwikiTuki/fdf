
#include "fdf.h"

int	fdf_mk_color(int transparency, int red, int green, int blue)
{
	int	color;

	color = 0;
	color = color | transparency;
	color = color << 8;
	color = color | red;
	color = color << 8;
	color = color | green;
	color = color << 8;
	color = color | blue;
	return (color);
}

void	fdf_print_pnt(t_point p)
{
	ft_printf("(%d, %d, %d)", p.x, p.y, p.z);
}

t_point	fdf_set_point(int x, int y, int z)
{
	t_point	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

void	fdf_load_point_color(t_point *p, char *color)
{
	char	*s;

	s = ft_strchr(color, ',');
	if (!s)
	{
		p->fixed_color = 0;
		return ;
	}
	if (ft_strncmp(s, ",0x", 3))
	{
		p->fixed_color = 0;
		return ;
	}
	else
	{
		p->fixed_color = 1;
		p->color = fdf_hex_int_atoi(s + 3, "0123456789ABCDEF");
	}
}
