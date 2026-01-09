/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:30:52 by dnantet           #+#    #+#             */
/*   Updated: 2026/01/08 21:03:21 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	d;

	i = 0;
	d = (char)c;
	while (s && s[i] != '\0')
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == d)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*cpy;

	if (!s)
		return (NULL);
	cpy = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;

	lsrc = ft_strlen((const char *)src);
	if (dst == NULL && size == 0)
		return (lsrc);
	ldst = ft_strlen((const char *)dst);
	if (size <= ldst)
		return (lsrc + size);
	if (lsrc < size - ldst)
		ft_memmove(dst + ldst, src, lsrc + 1);
	else
	{
		ft_memmove(dst + ldst, src, size - ldst - 1);
		dst[size - 1] = '\0';
	}
	return (ldst + lsrc);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lsrc;

	i = 0;
	lsrc = ft_strlen(src);
	if (size == 0)
		return (lsrc);
	else if (size > lsrc + 1)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (lsrc);
}
