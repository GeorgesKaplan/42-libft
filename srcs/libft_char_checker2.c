/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_char_checker2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:09:07 by dnantet           #+#    #+#             */
/*   Updated: 2026/01/17 13:20:07 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_uppercase(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_lowercase(int c)
{
	return (c >= 'a' && c <= 'z');
}
