/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/17 19:09:24 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void leaks_check()
{
	system("leaks push_swap");
	ft_printf("-------------------------------------------------------\n");
}

int main(int argc, char **argv)
{
	atexit(leaks_check);
	t_node	*a;
	// t_node	*b;
	int		err;

	(void) a;
	err = validate_input(argc, argv, &a);
	if (err == NO_PARAMETERS)
		exit(EXIT_SUCCESS);
	if (err < 0)
		return (ft_printf("%d\n", err), write(2, "Error\n", 6), FAILURE);
	t_node	*pass;

	pass = a;
	while (pass)
	{
		ft_printf("%d\n", pass->num);
		pass = pass->next;
	}
	ft_lstclear(&a);
}
