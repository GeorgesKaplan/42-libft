/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_char_checker2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:09:07 by dnantet           #+#    #+#             */
/*   Updated: 2025/11/28 17:25:36 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

/**
** @brief Checks if a string is empty (no characters or only spaces).
**
** @param str The string to check.
** @return 0 or 1 as a boolean value.
**/
int	is_string_empty(char *str)
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
