/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:03:06 by dnantet           #+#    #+#             */
/*   Updated: 2026/02/10 12:23:35 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fdprintchar(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_fdprintstr(int fd, char *str)
{
	int	i;

	if (!str)
	{
		i = ft_fdprintstr(fd, "(null)");
		return (i);
	}
	i = 0;
	while (str && str[i])
		i += ft_fdprintchar(fd, str[i]);
	return (i);
}

int	ft_fdprintint(int fd, int n)
{
	int	size;
	int	mag;
	int	tmp;
	int	sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_fdprintstr(fd, "-2147483648"));
	if (n < 0)
	{
		n *= -1;
		sign += ft_fdprintchar(fd, '-');
	}
	size = ft_get_nb_size(n);
	mag = ft_get_nb_mag(size);
	tmp = n;
	while (mag > 0)
	{
		n /= mag;
		ft_fdprintchar(fd, n + '0');
		n = tmp % mag;
		mag /= 10;
	}
	return (size + sign);
}

int	ft_printuint(int fd, unsigned int n)
{
	int				size;
	int				mag;
	unsigned int	tmp;

	size = ft_get_nb_size(n);
	mag = ft_get_nb_mag(size);
	tmp = n;
	while (mag > 0)
	{
		n /= mag;
		ft_fdprintchar(fd, n + '0');
		n = tmp % mag;
		mag /= 10;
	}
	return (size);
}
