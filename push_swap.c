/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/14 19:18:57 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		err;

	err = validate_input(argc, argv, a);
	if (err < 0)
		return (write(2, "Error\n", 6), FAILURE);
}