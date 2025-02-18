
#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# include <stdio.h>

typedef struct s_flags
{	
	char	type;	
	int		error;
	int		dash;
	int		zero;
	int		dot;
	int		hashtag;
	int		space;
	int		plus;
	int		padding;
	int		precision;
}	t_flags;
int		ft_printf(const char *format, ...);
//
//void	ft_flstr(va_list args, t_flags flags);
int		ft_flchar(char **str, va_list args, t_flags flags);
int		ft_flstring(char **str, va_list args, t_flags flags);
size_t	ft_flnums(char **str, va_list args, t_flags flags);

////
int		fd_printf(int fd, char const *str, ...);
#endif
