/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/20 20:33:27 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void leaks_check()
{
	ft_printf("---------------------------\n");
	system("leaks -q push_swap");
	ft_printf("------------------------- END ------------------------------\n");
}

int main(int argc, char **argv)
{
	atexit(leaks_check);
	t_stack			a;
	t_stack			b;
	t_node			*top_a;
	int				err;

	top_a = NULL;
	a = (t_stack) {top_a, 0, A};
	ft_printf("------------------------- START ------------------------------\n");
	err = validate_input(argc, argv, &a);
	if (err == NO_PARAMETERS || err == ALREADY_SORTED)
		exit(EXIT_SUCCESS);
	if (err < 0)
		return (ft_printf("%d\n", err), write(2, "Error\n", 6), FAILURE);
	t_node	*pass;

	ft_printf("-------- The stack --------\n");
	pass = a.top;
	while (pass)
	{
		ft_printf("%d\n", pass->num);
		pass = pass->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);
	/*
	// ---
	t_node	*node1 = ft_lstnew(6);
	t_node	*node2 = ft_lstnew(7);
	node1->next = node2;
	b.top = node1;
	b.size = 2;
	b.type = B;
	// ---

	ft_printf("---------------------------\n");
	ft_printf("After swapping the top elements of a\n");
	ft_swap(&a);
	t_node	*pass2;

	pass2 = a.top;
	while (pass2)
	{
		ft_printf("%d\n", pass2->num);
		pass2 = pass2->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);

	ft_printf("---------------------------\n");
	ft_printf("After pushing the top element of b to a\n");

	ft_push(&a, &b);

	t_node	*pass3;

	pass3 = a.top;
	while (pass3)
	{
		ft_printf("%d\n", pass3->num);
		pass3 = pass3->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);

	ft_printf("how b will look like\n");
	t_node	*stuff;
	stuff = b.top;
	while (stuff)
	{
		ft_printf("%d\n", stuff->num);
		stuff = stuff->next;
	}
	ft_printf("The size of stack b is %u\n ", b.size);

	ft_printf("---------------------------\n");

	ft_printf("After rotation of a\n");

	ft_rotate(&a);

	t_node	*pass4;

	pass4 = a.top;
	while (pass4)
	{
		ft_printf("%d\n", pass4->num);
		pass4 = pass4->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);
	ft_printf("---------------------------\n");
	ft_printf("After reversing the rotation of a\n");

	ft_rev_rotate(&a);

	t_node	*pass5;

	pass5 = a.top;
	while (pass5)
	{
		ft_printf("%d\n", pass5->num);
		pass5 = pass5->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size); */
	ft_printf("---------------------------\n");
	ft_sort(&a, NULL);
	ft_printf("After sorting the stack a\n");

	t_node	*pass6;
	pass6 = a.top;
	while (pass6)
	{
		ft_printf("%d\n", pass6->num);
		pass6 = pass6->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);

	ft_printf("---------------------------\n");
	ft_printf("Getting the the to mins of stack a\n\n");
	int min;
	int pos = ft_min(&a, &min);
	ft_printf("min1 = |%d|\nposition = |%d|\n", min, pos);
	set_in_top(&a, min);

	t_node	*pass7;
	pass7 = a.top;
	while (pass7)
	{
		ft_printf("%d\n", pass7->num);
		pass7 = pass7->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);
	ft_lstclear(&a.top);
	ft_lstclear(&b.top);
}
