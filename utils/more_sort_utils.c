/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:18:45 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/21 17:58:48 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	return_index(int *arr, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == number)
			return (i);
		i++;
	}
	return (FAILURE);
}

void	index_stack(t_stack *stack)
{
	int		*array;
	t_node	*pass;
	int		i;

	array = malloc(sizeof(int) * stack->size);
	if (!array) // I can set an error handling mechanism with an err parameter
		return ;
	i = 0;
	pass = stack->top;	
	while (pass)
	{
		array[i++] = pass->num;
		pass = pass->next;
	}
	ft_bubble_sort(array, stack->size);
	pass = stack->top;	
	while (pass)
	{
		pass->index = return_index(array, stack->size, pass->num);
		pass = pass->next;
	}
	free(array);
}

unsigned int	ft_max(t_stack *stack, int *max)
{
	t_node	*pass;
	int		iters;
	unsigned int	pos;

	*max = (stack->top)->num;
	pass = stack->top;
	iters = 0;
	pos = 0;
	while (pass)
	{
		if (pass->num > *max)
		{
			*max = pass->num;
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
	t_node			*travel;

	min = 0;
	max = 8;
	t_node	*pass = a->top;
	while (pass)
	{
		ft_printf("|%d|\n", pass->num);
		pass = pass->next;
	}
	ft_printf("---------------------------\n");
	travel = a->top;
	while (a->size)
	{
		index = (a->top)->index;
		ft_printf("Current number at the top of the stack: %d\n", (a->top)->num);
		ft_printf("Assosciated index: %d\n", (a->top)->index);
		if (index >= min && index <= max)
		{	// push it to b
			// update the range
			ft_push(b, a);
			min++;
			max++;
		}
		else if (index > max)
		{	// get it to the bottom (a simple ra I believe)
			ft_rotate(a); ft_printf("HNA?\n");
			// break ;
		}
		else
		{
			// push to b then ra to make it at the bottom
			ft_push(b, a);
			ft_rotate(b);
			min++;
			max++;
		}
	}
	ft_printf("Current number at the top of the stack: %d\n", (a->top)->num);
	ft_printf("Assosciated index: %d\n", (a->top)->index);
	t_node	*pass2 = a->top;
	while (pass2)
	{
		ft_printf("|%d|\n", pass2->num);
		pass2 = pass2->next;
	}
}
#include <stdio.h>
void ft_sort_more(t_stack *a, t_stack *b)
{
	int	max;
	unsigned int	pos;

	ft_range(a, b);
	// ft_printf("After applying the range on stack a, the following is the structure of stack b\n");
	while (b->top)
	{
		pos = ft_max(b, &max);
		set_in_top(b, pos);
		// printf("This is the top of stack b: %d\n", (b->top)->num);
		ft_push(a, b);
	}
}
