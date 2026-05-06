/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_gnl2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:52:21 by dnantet           #+#    #+#             */
/*   Updated: 2026/05/06 12:56:47 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**get_gnl_storage(void)
{
	static char	*next_line_start[1024];

	return (next_line_start);
}

void	clear_get_next_line(int fd)
{
	char	**next_line_start;

	if (fd < 0 || fd >= 1024)
		return ;
	next_line_start = get_gnl_storage();
	free(next_line_start[fd]);
	next_line_start[fd] = NULL;
}
