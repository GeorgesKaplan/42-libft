/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string_utils5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:10:19 by dnantet           #+#    #+#             */
/*   Updated: 2026/02/23 11:21:11 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	legal_free(char *s1, int s1_allocd, char *s2, int s2_allocd)
{
	if (s1 && s1_allocd)
		free(s1);
	if (s2 && s2_allocd)
		free(s2);
}

static void	init_stuff(int *i, int *j, int *s1_allocd, int *s2_allocd)
{
	*i = 0;
	*j = 0;
	*s1_allocd = 0;
	*s2_allocd = 0;
}

static void	alloc_stuff(char *s1, int *s1_allocd, char *s2, int *s2_allocd)
{
	if (!s1)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		*s1_allocd = 1;
	}
	if (!s2)
	{
		s2 = (char *)ft_calloc(1, sizeof(char));
		*s2_allocd = 1;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*jstr;
	int		i;
	int		j;
	int		s1_allocd;
	int		s2_allocd;

	init_stuff(&i, &j, &s1_allocd, &s2_allocd);
	alloc_stuff(s1, &s1_allocd, s2, &s2_allocd);
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
	legal_free(s1, s1_allocd, s2, s2_allocd);
	return (jstr);
}
