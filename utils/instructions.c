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

void	ft_rotate(t_node **stack)
{
	t_node	*node;
	t_node	*first_node;
	int		tmp;

	if (!stack || !(*stack))
		return ;
	node = *stack;
	first_node = *stack;
	tmp = first_node->num;
	while (node->next)
	{
		tmp = (node->next)->num;
		(node->next)->num = node->num;
		node = node->next;
	}
	first_node->num = tmp;
}

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
