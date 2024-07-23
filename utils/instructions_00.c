/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:58:08 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/23 18:34:26 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*node;

	if (!stack || !(stack->top))
		return ;
	node = (stack->top)->next;
	(stack->top)->next = node->next;
	node->next = stack->top;
	stack->top = node;
	if (stack->type == A)
		ft_printf("sa\n");
	if (stack->type == B)
		ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}

void	ft_push(t_stack *stack1, t_stack *stack2)
{
	t_node	*node;

	if (!stack1 || !stack2 || !stack2->top)
		return ;
	node = stack2->top;
	stack2->top = node->next;
	node->next = NULL;
	ft_lstadd_front(&stack1->top, node);
	stack1->size++;
	stack2->size--;
	if (stack1->type == A)
		ft_printf("pa\n");
	if (stack1->type == B)
		ft_printf("pb\n");
}

void	ft_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*tmp;

	if (!stack || !stack->top)
		return ;
	tmp = (stack->top)->next;
	last = ft_lstlast(stack->top);
	(stack->top)->next = NULL;
	last->next = stack->top;
	stack->top = tmp;
	if (stack->type == A)
		ft_printf("ra\n");
	if (stack->type == B)
		ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
