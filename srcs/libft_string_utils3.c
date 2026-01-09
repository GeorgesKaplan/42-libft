/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:46:55 by dnantet           #+#    #+#             */
/*   Updated: 2026/01/08 21:03:22 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	char	*tstr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == '\0')
	{
		tstr = ft_calloc(1, sizeof(char));
		if (!tstr)
			return (NULL);
		return (tstr);
	}
	while (is_set(set, s1[i]))
		i++;
	while (is_set(set, s1[j]))
		j--;
	tstr = ft_substr(s1, i, j - i + 1);
	return (tstr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = ft_calloc(1, sizeof(char));
		if (!sub)
			return (NULL);
		return (sub);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*jstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
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
	free(s1);
	return (jstr);
}
