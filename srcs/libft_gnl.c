/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:25:28 by dnantet           #+#    #+#             */
/*   Updated: 2026/01/08 21:03:17 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_for_new_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*create_line(int fd, char *line)
{
	ssize_t	prog;
	char	*buf;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	while (1)
	{
		prog = read(fd, buf, BUFFER_SIZE);
		if (prog == -1)
		{
			free(line);
			free(buf);
			return (NULL);
		}
		if (prog == 0)
			break ;
		buf[prog] = '\0';
		line = ft_strjoin(line, buf);
		if (check_for_new_line(buf))
			break ;
	}
	free(buf);
	return (line);
}

static char	*gnl_start(char *full_line)
{
	char	*next_line_start;
	ssize_t	i;

	i = 0;
	while (!(full_line[i] == '\0' || full_line[i] == '\n'))
		i++;
	if (full_line[i] == '\0' || full_line[i + 1] == '\0')
		return (NULL);
	next_line_start = ft_substr(full_line, i + 1, ft_strlen(full_line) - i);
	if (full_line[0] == '\0')
	{
		free(full_line);
		full_line = NULL;
	}
	full_line[i + 1] = '\0';
	return (next_line_start);
}

char	*get_next_line(int fd)
{
	static char	*next_line_start[1024];
	char		*full_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = create_line(fd, next_line_start[fd]);
	if (!full_line)
		return (NULL);
	next_line_start[fd] = gnl_start(full_line);
	return (full_line);
}
