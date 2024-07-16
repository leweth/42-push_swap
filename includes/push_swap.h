/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:36 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/16 18:21:11 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../includes/ft_printf.h"

# define SUCCESS 0
# define FAILURE -1

/* Errors defintions */

# define NO_PARAMETERS -11
# define WRONG_NUMBER_FORMAT -12
# define NUMBER_EXCCED_INT_MAX -13
# define NUMBER_LOWER_THAN_INT_MIN -14
# define FAILED_MALLOC_ERR -21

/* Struct definition */

typedef struct s_node
{
	int				num;
	struct s_node	*next;
} t_node;

int		validate_input(int argc, char **argv, t_node *a);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char *str);
void	lst_add_back(t_node **lst, t_node *node);
int		ft_atoi(char *str, int *err);
bool	ft_isdigit(int c);

#endif