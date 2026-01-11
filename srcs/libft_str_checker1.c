/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str_checker1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:39:04 by dnantet           #+#    #+#             */
/*   Updated: 2026/01/11 12:42:53 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** @brief Checks if a string contains exactly one word
** (eventually begins and ends with whitespace).
**
** @param str The string to check.
** @return 0 or 1 as a boolean value.
**/
int	is_single_word_string(char *str)
{
	int	i;
	int	word_found;

	if (!str)
		return (0);
	i = 0;
	word_found = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			if (word_found)
				return (0);
			word_found = 1;
			while (str[i] && !is_space(str[i]))
				i++;
		}
		else
			i++;
	}
	return (word_found);
}

/**
** @brief Checks if a string is empty (contains no characters
** or contains only spaces).
**
** @param str The string to check.
** @return 0 or 1 as a boolean value.
**/
int	is_empty_string(char *str)
{
	const int	size = ft_strlen(str);
	int			i;

	i = 0;
	if (size == 0)
		return (1);
	else
	{
		while (i < size)
		{
			if (!is_space(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
}

/**
** @brief Checks if a string is a number. Can be a decimal number of any size.
**
** @param str The string to check.
** @return 0 or 1 as a boolean value.
**/
static int	is_number_check(char *str, int *i, int *has_digit,
	int *has_decimal_point)
{
	while (str[*i])
	{
		if (ft_isdigit(str[*i]))
			*has_digit = 1;
		else if (str[*i] == '.')
		{
			if (*has_decimal_point)
				return (0);
			*has_decimal_point = 1;
		}
		else if (is_space(str[*i]))
			break ;
		else
			return (0);
		*i += 1;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;
	int	has_digit;
	int	has_decimal_point;

	if (!str)
		return (0);
	i = 0;
	has_digit = 0;
	has_decimal_point = 0;
	while (is_space(str[i]))
		i++;
	if (is_sign(str[i]))
		i++;
	if (!is_number_check(str, &i, &has_digit, &has_decimal_point))
		return (0);
	while (is_space(str[i]))
		i++;
	return (str[i] == '\0' && has_digit);
}
