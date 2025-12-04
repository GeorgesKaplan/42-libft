/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:52:26 by dnantet           #+#    #+#             */
/*   Updated: 2025/11/28 17:54:24 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elt;

	elt = ft_calloc(1, sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!(lst || del))
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_elt;

	if (!(*lst || lst || del))
		return ;
	while (*lst)
	{
		next_elt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_elt;
	}
	*lst = NULL;
}

void	ft_lstadd_front(t_list **lst, t_list *new_list)
{
	if (!(*lst || lst || new_list))
		return ;
	new_list->next = *lst;
	*lst = new_list;
}

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list	*last_elt;

	if (!(lst || new_list))
		return ;
	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	last_elt = ft_lstlast(*lst);
	if (!last_elt)
		*lst = new_list;
	last_elt->next = new_list;
}
