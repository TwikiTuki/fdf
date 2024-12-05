
#include "fdf.h"

int	fdf_calloc_matrix_mem(t_matrix *matrix, t_point	dims)
{
	int		row;

	matrix->nr = dims.y;
	matrix->nc = dims.x;
	if (!dims.x || !dims.y)
		return (0);
	matrix->points = (t_point **) ft_calloc(sizeof(t_point *),
			(matrix->nr + 1));
	if (!matrix->points)
		return (0);
	row = 0;
	while (row < matrix->nr)
	{
		matrix->points[row] = (t_point *) ft_calloc(sizeof(t_point),
				(matrix->nc + 1));
		if (!matrix->points[row])
		{
			fdf_abort_matrix(matrix);
			return (0);
		}
		row++;
	}
	return (1);
}

t_matrix	*fdf_abort_matrix(t_matrix *matrix)
{
	if (matrix->points)
		free_matrix((void **)matrix->points);
	matrix->nr = 0;
	matrix->nc = 0;
	return (matrix);
}

int	fdf_matrix_init_2(int f, t_matrix *matrix, t_point dims);

t_matrix	fdf_matrix_init(char *file)
{
	int			f;
	t_matrix	matrix;
	t_point		dims;

	ft_memset(&matrix, 0, sizeof(t_matrix));
	dims = get_dims_from_file(file);
	if (!fdf_calloc_matrix_mem(&matrix, dims))
		return (*(fdf_abort_matrix(&matrix)));
	f = open(file, O_RDONLY);
	if (f < 0)
		return (*(fdf_abort_matrix(&matrix)));
	if (!fdf_matrix_init_2(f, &matrix, dims))
		return (*(fdf_abort_matrix(&matrix)));
	close(f);
	return (matrix);
}

int	fdf_matrix_init_2(int f, t_matrix *matrix, t_point dims)
{
	char		*line;
	char		**numbers;
	int			p[2];

	line = get_next_line(f);
	p[0] = 0;
	while (line)
	{
		numbers = ft_split(line, ' ');
		free(line);
		if (!numbers)
			return (0);
		p[1] = 0;
		while (numbers[p[1]] && numbers[p[1]][0] != '\n')
		{
			matrix->points[p[0]][p[1]] = fdf_set_point(p[1] - dims.x / 2,
					p[0] - dims.y / 2, ft_atoi(numbers[p[1]]));
			fdf_load_point_color(&matrix->points[p[0]][p[1]], numbers[p[1]]);
			p[1]++;
		}
		free_matrix((void **) numbers);
		line = get_next_line(f);
		p[0]++;
	}
	return (1);
}

void	fdf_print_matrix(t_matrix matrix)
{
	int		row;
	int		col;
	t_point	p;

	row = 0;
	while (row < matrix.nr)
	{
		col = 0;
		while (col < matrix.nc)
		{
			p = matrix.points[row][col];
			if (matrix.points[row][col].fixed_color)
				ft_printf("%d,%#X ", p.z, p.color);
			else if (p.color < 16 && p.x > 0)
				ft_printf("%d ", p.z);
			else
				ft_printf("%d ", p.z);
			col++;
		}
		ft_printf("\n");
		row++;
	}
}
