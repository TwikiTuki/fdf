/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:22:29 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/29 11:03:23 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nums(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == MAL_INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	print_nums(n, fd);
}

void	print_nums(int n, int fd)
{
	char	c;

	c = n % 10 + '0';
	n /= 10;
	if (n)
		print_nums(n, fd);
	write(fd, &c, 1);
}
