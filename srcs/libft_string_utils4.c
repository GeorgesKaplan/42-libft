/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string_utils4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:19:18 by dnantet           #+#    #+#             */
/*   Updated: 2026/02/20 12:30:24 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/**
** @brief Searches a substring in a string.
**
** @param big The string in which to search.
** @param little The string to find.
** @return The rest of ```big``` starting from ```little```
** or an empty string if not found.
**/
char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

/**
* @brief Joins an array of strings into a single string.
*
* @param arr The string array to convert. Must be NULL-terminated.
*
* @return A single string allocated in memory.
*/
char	*ft_rejoin(char **arr)
{
	int		i;
	char	*line;
	char	*tmp;

	if (!arr)
	{
		line = ft_strdup("");
		return (line);
	}
	line = ft_strdup(arr[0]);
	if (!arr[1])
		return (line);
	i = 1;
	while (arr && arr[i])
	{
		tmp = ft_strjoin(line, arr[i]);
		free(line);
		line = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (line);
}
