/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split_keep_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:54:46 by dnantet           #+#    #+#             */
/*   Updated: 2026/02/20 11:58:17 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_count_parts_vars(int *i, int *start, int *count)
{
	*i = 0;
	*start = 0;
	*count = 0;
}

int	count_parts(char *str, char sep)
{
	int	i;
	int	start;
	int	count;
	int	j;

	init_count_parts_vars(&i, &start, &count);
	while (str && str[i])
	{
		if (str[i] == sep)
		{
			if (i > start)
				count++;
			j = i + 1;
			while (str[j] && str[j] != sep)
				j++;
			count++;
			i = j;
			start = j;
		}
		else
			i++;
	}
	if (str && i > start)
		count++;
	return (count);
}
