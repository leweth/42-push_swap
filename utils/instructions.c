/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:58:08 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/18 13:18:59 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*node;
	int		tmp;

	if (!stack || !(*stack))
		return ;
	node = *stack;
	tmp = node->num;
	node->num = (node->next)->num;
	(node->next)->num = tmp;
}

void	ft_ss(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_push(t_node **stack1, t_node **stack2) //takes the first element at the top of stack2 and put it at the top of stack1
{
	int		tmp;
	t_node	*node;

	if (!stack1 || !stack2 || !(*stack2))
		return ;
	tmp = (*stack2)->num;
	node = ft_lstnew(tmp);
	ft_lstadd_front(stack1, node);
}

void	ft_rotate(t_node **stack) // [4] [5]
{
	t_node	*node;
	t_node	*first_node;
	int		first;

	if (!stack || !(*stack))
		return ;
	node = *stack; // [6]
	first_node = *stack; // [6]
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