/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_char_checker2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:09:07 by dnantet           #+#    #+#             */
/*   Updated: 2026/01/07 10:54:22 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

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
