/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/23 19:55:26 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// void leaks_check() 
// {
// 	ft_printf("---------------------------\n");
// 	system("leaks push_swap");
// 	ft_printf("------------------------- END ------------------------------\n");
// }

int main(int argc, char **argv)
{
	// atexit(leaks_check);
	t_stack			a;
	t_stack			b;
	int				err;

	a = (t_stack) {NULL, 0, A, 0, 20};
	b = (t_stack) {NULL, 0, B, 0, 20};
	err = validate_input(argc, argv, &a);
	if (err == NO_PARAMETERS || err == ALREADY_SORTED)
		exit(EXIT_SUCCESS);
	if (err < 0)
		return (write(2, "Error\n", 6), FAILURE);
	index_stack(&a);
	if (a.size > 100)
	{
		a.min_range = MIN_500;
		a.max_range = MAX_500;
	}
	else
	{
		a.min_range = MIN_100;
		a.max_range = MAX_100;
	}
	ft_sort(&a, &b);
	ft_lstclear(&a.top);
	ft_lstclear(&b.top);
}
