/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:36 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/14 19:15:16 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>

# define SUCCESS 0
# define FAILURE -1

/* Errors defintions */

# define NO_PARAMETERS


/* Struct definition */

typedef struct s_node
{
	int				num;
	struct s_node	*next;
} t_node;

int	validate_input(int argc, char **argv, t_node *a);
#endif