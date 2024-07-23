/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:34:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/23 18:34:29 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_rotate(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	if (!stack || !(stack->top))
		return ;
	node = stack->top;
	while (node->next)
	{
		tmp = (node->next);
		if (tmp->next == NULL)
			break ;
		node = node->next;
	}
	tmp->next = stack->top;
	stack->top = tmp;
	node->next = NULL;
	if (stack->type == A)
		ft_printf("rra\n");
	if (stack->type == B)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}
