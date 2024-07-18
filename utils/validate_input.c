/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:06:50 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/18 11:53:30 by mben-yah         ###   ########.fr       */
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

	pass = *a;
	while (pass)
	{
		if (pass->num == number)
			return (true);
		pass = pass->next;
	}
	return (false);
}

static bool	is_sorted(t_node **a)
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

int	validate_input(int argc, char **argv, t_node **a)
{
	int		err;
	int		i;
	char	**strs;
	t_node	*node;
	int		j;
	int		num;

	err = 0;
	if (argc == 1)
		return (err = NO_PARAMETERS, err);
	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i]);
		// for (int a = 0; strs[a]; a++)
		// 	ft_printf("|%s|\n", strs[a]);
		if (!strs)
			return (FAILED_MALLOC_ERR);
		if (!(*strs))
			return (ft_lstclear(a), free(strs), strs= NULL, EMPTY_PARAMETERS);
		j = 0;
		while (strs[j])
		{
			num = ft_atoi(strs[j], &err);
			// ft_printf("The number  after atoi: %d\n", num);
			if (err < 0)
				return (clean_strs(&strs), ft_lstclear(a), err);
			if (is_duplicate(a, num))
				return (err = DUPLICATE_FOUND, clean_strs(&strs), ft_lstclear(a), err);				
			node = ft_lstnew(num);
			if (!node)
				return (err = FAILED_MALLOC_ERR, clean_strs(&strs), ft_lstclear(a), err);
			ft_lstadd_back(a, node);
			j++;
		}
		clean_strs(&strs);
		i++;
	}
	if (is_sorted(a))
		return (ft_lstclear(a), ALREADY_SORTED);
	return (SUCCESS);
}
