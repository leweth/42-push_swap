/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:20:56 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/23 18:31:59 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_bubble_sort(int *arr, int size)
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

static int	return_index(int *arr, int size, int number)
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
	if (!array)
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
