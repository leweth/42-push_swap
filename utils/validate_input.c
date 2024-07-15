/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:06:50 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/15 13:06:51 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	validate_input(int argc, char **argv, t_node *a)
{
	int	err; // this will be passed to atoi as a param since we can't have it return the errors
	if (argc == 1)
		return (NO_PARAMETERS);
	
}