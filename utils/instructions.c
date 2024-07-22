
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
/* 
void	ft_rotate_(t_stack *stack) // [4] [5]
{
	t_node	*node;
	t_node	*first_node;
	int		first_num;
	int		first_index;

	if (!stack || !stack->top)
		return ;
	node = stack->top; // [6]
	first_node = stack->top; // [6]
	first_num = first_node->num; // 6
	first_index = first_node->index; // 
	ft_lstlast(stack->top);
	while (node->next) // [4] [NULL]
	{
		node->num = (node->next)->num;
		node->index = (node->next)->index;
		node = node->next; // [5]
	}
	node->num = first_num; // [5]
	node->index = first_index;
	if (stack->type == A)
		ft_printf("ra\n");
	if (stack->type == B)
		ft_printf("rb\n");
}
 */
void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}

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
/* 
void	ft_rev_rotate(t_stack *stack)
{
	t_node	*node;
	t_node	*first_node;
	int		tmp1;
	int		tmp2;
	int		prv_num;
	int		prv_index;

	if (!stack || !(stack->top))
		return ;
	node = stack->top;
	first_node = stack->top;
	prv_num = first_node->num;
	prv_index = first_node->index;
	while (node->next)
	{
		tmp1 = (node->next)->num;
		(node->next)->num = prv_num;
		prv_num = tmp1;
		node = node->next;
	}
	first_node->num = prv_num;
	if (stack->type == A)
		ft_printf("rra\n");
	if (stack->type == B)
		ft_printf("rrb\n");
} */

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