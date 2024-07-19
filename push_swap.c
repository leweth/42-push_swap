/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/19 22:49:23 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void leaks_check()
{
	system("leaks push_swap");
	ft_printf("------------------------- END ------------------------------\n");
}

int main(int argc, char **argv)
{
	atexit(leaks_check);
	t_node	*a;
	t_node	*b;
	int		err;

	a = NULL;
	ft_printf("------------------------- START ------------------------------\n");
	err = validate_input(argc, argv, &a);
	if (err == NO_PARAMETERS || err == ALREADY_SORTED)
		exit(EXIT_SUCCESS);
	if (err < 0)
		return (ft_printf("%d\n", err), write(2, "Error\n", 6), FAILURE);
	t_node	*pass;

	ft_printf("-------- The stack --------\n");
	pass = a;
	while (pass)
	{
		ft_printf("%d\n", pass->num);
		pass = pass->next;
	}

	/*  */
	t_node	*node1 = ft_lstnew(6);
	t_node	*node2 = ft_lstnew(7);
	node1->next = node2;
	b = node1;
	/*  */

	ft_printf("---------------------------\n");
	ft_printf("After swapping the top elements of a\n");
	ft_swap(&a);
	t_node	*pass2;

	pass2 = a;
	while (pass2)
	{
		ft_printf("%d\n", pass2->num);
		pass2 = pass2->next;
	}
	ft_printf("---------------------------\n");
	ft_printf("After pushing the top element of b to a\n");

	ft_push(&a, &b);

	t_node	*pass3;

	pass3 = a;
	while (pass3)
	{
		ft_printf("%d\n", pass3->num);
		pass3 = pass3->next;
	}

	ft_printf("how b will look like\n");
	t_node	*stuff;
	stuff = b;
	while (stuff)
	{
		ft_printf("%d\n", stuff->num);
		stuff = stuff->next;
	}
	ft_printf("---------------------------\n");

	ft_printf("After rotation of a\n");

	ft_rotate(&a);

	t_node	*pass4;

	pass4 = a;
	while (pass4)
	{
		ft_printf("%d\n", pass4->num);
		pass4 = pass4->next;
	}
	ft_printf("---------------------------\n");
	ft_printf("After reversing the rotation of a\n");

	ft_rev_rotate(&a);

	t_node	*pass5;

	pass5 = a;
	while (pass5)
	{
		ft_printf("%d\n", pass5->num);
		pass5 = pass5->next;
	}
	ft_printf("---------------------------\n");
	ft_lstclear(&a);
	ft_lstclear(&b);
}
