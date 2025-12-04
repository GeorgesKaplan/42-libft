/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:27:22 by dnantet           #+#    #+#             */
/*   Updated: 2025/11/28 17:29:51 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' && nptr[i + 1] != '-')
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

static int	get_size(long n)
{
	long	size;

	size = 0;
	if (n < 0)
	{
		size += 1;
		n *= -1;
	}
	if (n == 0)
		size += 1;
	while (n > 0)
	{
		size += 1;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		size;
	long	ln;

	ln = n;
	size = get_size(ln);
	nb = ft_calloc((size + 1), sizeof(char));
	if (!nb)
		return (NULL);
	if (ln < 0)
	{
		ln *= -1;
		nb[0] = '-';
	}
	if (ln == 0)
	{
		nb[0] = '0';
		return (nb);
	}
	while (ln > 0)
	{
		nb[--size] = ((ln % 10) + '0');
		ln /= 10;
	}
	return (nb);
}
