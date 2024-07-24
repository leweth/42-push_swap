/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:06:50 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/23 21:29:22 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	clean_strs(char ***strs)
{
	char	**ptrs;
	int		i;

	i = 0;
	ptrs = *strs;
	while (ptrs[i])
	{
		free(ptrs[i]);
		ptrs[i] = NULL;
		i++;
	}
	free(ptrs);
	strs = NULL;
}

static bool	is_duplicate(t_node **a, int number)
{
	t_node	*pass;

	if (!a)
		return (false);
	pass = *a;
	while (pass)
	{
		if (pass->num == number)
			return (true);
		pass = pass->next;
	}
	return (false);
}

bool	is_sorted(t_node **a)
{
	int		prev;
	t_node	*pass;

	if (!a || !(*a))
		return (true);
	pass = *a;
	prev = pass->num;
	while (pass)
	{
		if (pass->num < prev)
			return (false);
		prev = pass->num;
		pass = pass->next;
	}
	return (true);
}

static int	add_nodes(t_stack *stack, char **strs)
{
	t_node	*node;
	int		j;
	int		num;
	int		err;

	j = 0;
	err = SUCCESS;
	while (strs[j])
	{
		num = ft_atoi(strs[j], &err);
		if (err < 0)
			return (clean_strs(&strs), ft_lstclear(&(stack->top)), err);
		if (is_duplicate(&(stack->top), num))
			return (err = DUPLICATE_FOUND, clean_strs(&strs), 
				ft_lstclear(&(stack->top)), err);
		node = ft_lstnew(num);
		if (!node)
			return (err = FAILED_MALLOC_ERR, clean_strs(&strs), 
				ft_lstclear(&(stack->top)), err);
		ft_lstadd_back(&(stack->top), node);
		(stack->size)++;
		j++;
	}
	return (err);
}

int	validate_input(int argc, char **argv, t_stack *stack)
{
	int		err;
	int		i;
	char	**strs;

	err = 0;
	if (argc == 1)
		return (err = NO_PARAMETERS, err);
	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i]);
		if (!strs)
			return (FAILED_MALLOC_ERR);
		if (!(*strs))
			return (ft_lstclear(&(stack->top)), free(strs), strs = NULL, 
				EMPTY_PARAMETERS);
		err = add_nodes(stack, strs);
		if (err < 0)
			return (err);
		clean_strs(&strs);
		i++;
	}
	if (is_sorted(&(stack->top)))
		return (ft_lstclear(&(stack->top)), ALREADY_SORTED);
	return (SUCCESS);
}
