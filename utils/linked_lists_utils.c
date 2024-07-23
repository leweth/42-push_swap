/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:50:13 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/23 18:35:56 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew(int number)
{
	t_node	*tmp;

	tmp = (t_node *) malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->num = number;
	tmp->index = NONE;
	tmp->next = NULL;
	return (tmp);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_lstclear(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		(*lst) = tmp;
	}
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	t_node	*node;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		node = (*lst);
		*lst = new;
		new->next = node;
	}
}
