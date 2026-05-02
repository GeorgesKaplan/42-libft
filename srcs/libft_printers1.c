/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printers1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:13:09 by dnantet           #+#    #+#             */
/*   Updated: 2026/05/02 12:42:16 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** @brief Prints an array of integers.
**
** @param array The array to print.
** @param int The size of the array.
** @return Nothing.
**/
void	print_int_array(int *array, int size)
{
	int	i;

	i = 0;
	if (array == NULL || size == 0)
	{
		ft_fdprintf(STDOUT_FILENO, "[]");
		return ;
	}
	ft_fdprintf(STDOUT_FILENO, "[");
	while (i < size)
	{
		ft_fdprintf(STDOUT_FILENO, "%d", array[i]);
		if (i < (size - 1))
			ft_fdprintf(STDOUT_FILENO, ", ");
		i++;
	}
	ft_fdprintf(STDOUT_FILENO, "]");
}

/**
** @brief Prints an array of strings. The array must be null-terminated.
**
** @param array The array to print.
** @return Nothing.
**/
void	print_str_array(char **array)
{
	int	i;

	i = 0;
	if (*array == NULL)
	{
		ft_fdprintf(STDOUT_FILENO, "[]");
		return ;
	}
	ft_fdprintf(STDOUT_FILENO, "[");
	while (array[i])
	{
		ft_fdprintf(STDOUT_FILENO, "\"%s\"", array[i]);
		if (array[i + 1] != NULL)
			ft_fdprintf(STDOUT_FILENO, ", ");
		i++;
	}
	ft_fdprintf(STDOUT_FILENO, "]");
}
