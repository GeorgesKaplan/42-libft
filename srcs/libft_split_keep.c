/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split_keep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:40:57 by dnantet           #+#    #+#             */
/*   Updated: 2026/02/20 12:20:43 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**init_split_keep_arr(char *str, char sep)
{
	char	**arr;
	int		parts;

	parts = count_parts(str, sep);
	arr = ft_calloc(parts + 1, sizeof(char *));
	return (arr);
}

static void	init_split_keep_indexes(int *indexes[4]) // i, j, start, idx
{
	*indexes[0] = 0;
	*indexes[1] = 0;
	*indexes[2] = 0;
	*indexes[3] = 0;
}

static void	split_keep_continued(char *str, char sep, char **arr,
	int *indexes[4]) // i, j, start, idx
{
	if (str[*indexes[0]] == sep)
	{
		if (*indexes[0] > *indexes[2])
		{
			arr[*indexes[3]] = ft_substr(str, *indexes[2],
					*indexes[0] - *indexes[2]);
			if (!arr[(*indexes[3])++])
				return (free_all(arr, (*indexes[3]) - 1));
		}
		*indexes[1] = *indexes[0] + 1;
		while (str[*indexes[1]] && str[*indexes[1]] != sep)
			(*indexes[1])++;
		arr[*indexes[3]] = ft_substr(str, *indexes[0],
				(*indexes[1]) - *indexes[0]);
		if (!arr[(*indexes[3])++])
			return (free_all(arr, (*indexes[3]) - 1));
		*indexes[0] = *indexes[1];
		*indexes[2] = *indexes[1];
	}
	else
		(*indexes[0])++;
}

/**
* @brief Splits a string into an array of strings at the given separator,
* keeping the separator at the start of the word.
*/
char	**ft_split_keep(char *str, char sep)
{
	char	**arr;
	int		indexes[4];

	arr = init_split_keep_arr(str, sep);
	if (!arr)
		return (NULL);
	init_split_keep_indexes(&indexes);
	while (str[indexes[0]])
		split_keep_continued(str, sep, arr, &indexes);
	if (indexes[0] > indexes[2])
	{
		arr[indexes[3]] = ft_substr(str, indexes[2], indexes[0] - indexes[2]);
		if (!arr[indexes[3]])
			return (free_all(arr, indexes[3] - 1));
		indexes[3]++;
	}
	arr[indexes[3]] = NULL;
	return (arr);
}
