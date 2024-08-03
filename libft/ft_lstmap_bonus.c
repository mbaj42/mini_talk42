/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:01:53 by mbaj              #+#    #+#             */
/*   Updated: 2024/06/27 15:01:49 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_elem(t_list *current, void (*del)(void *))
{
	if (current->next != NULL)
		free_elem(current->next, del);
	(del)(current -> content);
	current->next = NULL;
	free(current);
	current = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev;
	t_list	*current;
	t_list	*start;

	prev = NULL;
	while (lst)
	{
		current = (t_list *)malloc(sizeof(t_list));
		if (!current)
			free_elem(current, del);
		current -> content = (f)(lst -> content);
		if (!current -> content)
			free_elem(current, del);
		if (prev != NULL)
			prev -> next = current;
		else
			start = current;
		prev = current;
		lst = lst -> next;
	}
	return (start);
}
