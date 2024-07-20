
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:58:08 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/19 22:46:31 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	if (!stack || !(stack->top))
		return ;
	node = stack->top;
	tmp = node->num;
	node->num = (node->next)->num;
	(node->next)->num = tmp;
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

void	ft_push(t_stack *stack1, t_stack *stack2) //takes the first element at the top of stack2 and put it at the top of stack1
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

void	ft_rotate(t_stack *stack) // [4] [5]
{
	t_node	*node;
	t_node	*first_node;
	int		first;

	if (!stack || !stack->top)
		return ;
	node = stack->top; // [6]
	first_node = stack->top; // [6]
	first = first_node->num; // 6
	while (node->next) // [4] [NULL]
	{
		// ft_printf("node's address: %p. The assosciated number: %d\n", node, node->num);
		// ft_printf("next node's address: %p. The assosciated number: %d\n", node->next, (node->next)->num);
		// ft_printf("%d\n", tmp);
		node->num = (node->next)->num;
		node = node->next; // [5]
	}
	node->num = first; // [5]
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

void	ft_rev_rotate(t_stack *stack)
{
	t_node	*node;
	t_node	*first_node;
	int		tmp;
	int		prv;

	if (!stack || !(stack->top))
		return ;
	node = stack->top;
	first_node = stack->top;
	prv = first_node->num;
	while (node->next)
	{
		tmp = (node->next)->num;
		(node->next)->num = prv;
		prv = tmp;
		node = node->next;
	}
	first_node->num = prv;
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

/* 
int		rec(t_node	*node)
{
	int	tmp;

	if (node->next)
		return (node->num);
	tmp = (node->next)->num;
	(node->next)->num = node->num;
	return (rec(node->next));
}

void	recursive_rotate(t_node **stack)
{
	t_node	*node;
	int		ret;

	if (!stack || !(*stack))
		return ;
	node = *stack;
	ret = rec(node);
	node->num = ret;
}
 */