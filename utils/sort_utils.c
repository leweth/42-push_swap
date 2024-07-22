/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:45:29 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/21 16:29:45 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static int check_case(t_node *node1, t_node *node2, t_node *node3)
{
	if (node1->num > node2->num && node2->num > node3->num)
		return (0);
	else if (node1->num > node2->num && node2->num < node3->num 
			&& node3->num < node1->num)
		return (1);
	else if (node1->num < node2->num && node2->num > node3->num
			&& node1->num < node3->num)
		return (2);
	else if (node1->num < node2->num && node2->num > node3->num
			&& node1->num > node3->num)
		return (3);
	else
		return (4);
}

int	ft_min(t_stack *stack, int *min)
{
	t_node	*pass;
	unsigned int		pos;
	int		iters;

	pass = stack->top;
	*min = (stack->top)->num;
	iters = 0;
	pos = 0;
	while (pass)
	{
		if (*min > pass->num)
		{
			*min = pass->num;
			pos = iters;
		}
		iters++;
		pass = pass->next;
	}
	return (pos);
}
/* 
static int	get_position(t_node *node, int number)
{
	int	pos;

	pos = 0;
	while (node)
	{
		if (node->num == number)
			return (pos);
		pos++;
		node = node->next;
	}
	return (FAILURE);
} */

void set_in_top(t_stack	*stack, unsigned int pos) // it should take the min
{
	unsigned int	iters;

	if (pos <= stack->size / 2)
	{
		iters = pos;
		while (iters--)
			ft_rotate(stack);
	}
	else
	{
		iters = stack->size - pos;
		while (iters--)
			ft_rev_rotate(stack);
	}
}


static void	ft_sort_three(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	int		case_check;

	node1 = stack->top;
	node2 = node1->next;
	node3 = node2->next;
	case_check = check_case(node1, node2, node3);
	if (case_check == 0)
	{
		ft_swap(stack);
		ft_rev_rotate(stack);
	}
	else if (case_check == 1)
		ft_rotate(stack);
	else if (case_check == 2)
	{
		ft_rev_rotate(stack);
		ft_swap(stack);
	}
	else if (case_check == 3)
		ft_rev_rotate(stack);
	else
		ft_swap(stack);
}

void ft_sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	pos = ft_min(a, &min);
	set_in_top(a, pos);
	ft_push(b, a);
	pos = ft_min(a, &min);
	set_in_top(a, pos);
	ft_push(b, a);
	ft_sort_three(a);
	ft_push(a, b);
	ft_push(a, b);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		ft_swap(a);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else
		ft_sort_more(a, b);
}
