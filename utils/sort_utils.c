/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:45:29 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/20 20:46:41 by mben-yah         ###   ########.fr       */
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
	int		pos;
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

void set_in_top(t_stack	*stack, int pos) // it should take the min
{
	int	iters;

	if (pos <= 2) // this wouldn't work in the case of a size 4 stack
	{
		iters = 2;
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

static void ft_sort_five(t_stack *a, t_stack *b)
{
	/* int	min1;
	int	min2;

	min1 = 0;
	min2 = 0;
	mins_of_stack(a, &min1, &min2); */
	(void) a;
	(void) b;
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

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		ft_swap(a);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else
		ft_sort_more(a);
}
