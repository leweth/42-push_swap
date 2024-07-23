/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:18:45 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/23 18:36:52 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

unsigned int	ft_min_pos(t_stack *stack)
{
	t_node			*pass;
	unsigned int	pos;
	int				iters;
	int				min;

	pass = stack->top;
	min = (stack->top)->num;
	iters = 0;
	pos = 0;
	while (pass)
	{
		if (min > pass->num)
		{
			min = pass->num;
			pos = iters;
		}
		iters++;
		pass = pass->next;
	}
	return (pos);
}

unsigned int	ft_max_pos(t_stack *stack)
{
	t_node			*pass;
	int				iters;
	unsigned int	pos;
	int				max;

	max = (stack->top)->num;
	pass = stack->top;
	iters = 0;
	pos = 0;
	while (pass)
	{
		if (pass->num > max)
		{
			max = pass->num;
			pos = iters;
		}
		iters++;
		pass = pass->next;
	}
	return (pos);
}

void	ft_range(t_stack *a, t_stack *b)
{
	unsigned int	min;
	unsigned int	max;
	unsigned int	index;

	min = a->min_range;
	max = a->max_range;
	while (a->size)
	{
		index = (a->top)->index;
		if (index >= min && index <= max)
		{
			ft_push(b, a);
			min++;
			max++;
		}
		else if (index > max)
			ft_rotate(a);
		else
		{
			ft_push(b, a);
			ft_rotate(b);
			min++;
			max++;
		}
	}
}

void	ft_sort_more(t_stack *a, t_stack *b)
{
	unsigned int	pos;

	ft_range(a, b);
	while (b->top)
	{
		pos = ft_max_pos(b);
		set_in_top(b, pos);
		ft_push(a, b);
	}
}
