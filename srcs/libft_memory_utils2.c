/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:37:24 by dnantet           #+#    #+#             */
/*   Updated: 2025/11/28 17:38:20 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;

	if (nmemb == 0 || size == 0)
	{
		tmp = malloc(0);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	if (nmemb > (size_t) - 1 / size)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, nmemb * size);
	return (tmp);
}

/**
** @brief Frees a table.
**
** @param tab The table to free. Must be NULL-terminated.
** @return Nothing.
**/
void	free_table(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
