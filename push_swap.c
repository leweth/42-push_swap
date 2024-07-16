/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/16 18:24:54 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int main(int argc, char **argv)
{
	// t_node	*a;
	// t_node	*b;
	int		err;

	err = validate_input(argc, argv, NULL);
	if (err < 0)
		return (ft_printf("%d\n", err), write(2, "Error\n", 6), FAILURE);
}
