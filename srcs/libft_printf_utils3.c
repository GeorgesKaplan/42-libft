/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:06:05 by dnantet           #+#    #+#             */
/*   Updated: 2025/11/28 18:07:10 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printhex(unsigned int n, int isupper)
{
	int				i;
	unsigned int	rem;
	char			buf[8];
	int				size;

	i = 0;
	if (n == 0)
	{
		size = ft_printchar('0');
		return (size);
	}
	while (n > 0)
	{
		rem = n % 16;
		if (rem < 10)
			buf[i] = '0' + rem;
		else
			buf[i] = ('a' - (32 * isupper)) + (rem - 10);
		i++;
		n = n / 16;
	}
	size = 0;
	while (--i >= 0)
		size += ft_printchar(buf[i]);
	return (size);
}

static int	ulongtohex(unsigned long n)
{
	int				i;
	unsigned long	rem;
	char			buf[16];
	int				size;

	i = 0;
	if (n == 0)
	{
		size = ft_printchar('0');
		return (size);
	}
	while (n > 0)
	{
		rem = n % 16;
		if (rem < 10)
			buf[i] = '0' + rem;
		else
			buf[i] = 'a' + (rem - 10);
		n = n / 16;
		i++;
	}
	size = 0;
	while (--i >= 0)
		size += ft_printchar(buf[i]);
	return (size);
}

int	ft_printaddress(void *ptr)
{
	int				size;
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!ptr)
	{
		size = ft_printstr("(nil)");
		return (size);
	}
	size = ft_printstr("0x");
	size += ulongtohex(address);
	return (size);
}

int	ft_get_nb_size(long n)
{
	int	size;

	size = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		size += 1;
		n /= 10;
	}
	return (size);
}

int	ft_get_nb_mag(int size)
{
	int	mag;

	mag = 1;
	while (size >= 2)
	{
		mag *= 10;
		size--;
	}
	return (mag);
}
