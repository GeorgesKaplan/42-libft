/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string_utils5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:10:19 by dnantet           #+#    #+#             */
/*   Updated: 2026/05/02 13:57:33 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*jstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	jstr = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!jstr)
		return (NULL);
	while (s1 && s1[i])
	{
		jstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		jstr[i++] = s2[j++];
	return (jstr);
}
