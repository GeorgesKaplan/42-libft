/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:59:10 by dnantet           #+#    #+#             */
/*   Updated: 2025/11/28 18:00:30 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	converter_process(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		size += (ft_printstr(va_arg(args, char *)));
	else if (c == 'p')
		size += (ft_printaddress(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		size += (ft_printint(va_arg(args, int)));
	else if (c == 'u')
		size += (ft_printuint(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		size += (ft_printhex(va_arg(args, int), c == 'X'));
	else if (c == '%')
		size += (ft_printchar('%'));
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		nb_char;
	va_list	args;

	if (!str)
		return (-1);
	i = 0;
	nb_char = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			nb_char += converter_process(str[i + 1], args);
			i++;
		}
		else
		{
			ft_printchar(str[i]);
			nb_char++;
		}
		i++;
	}
	va_end(args);
	return (nb_char);
}
