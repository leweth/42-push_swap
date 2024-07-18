/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:36 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/18 10:39:49 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "../includes/ft_printf.h"

# define SUCCESS 0
# define FAILURE -1

/* Errors defintions */

# define EMPTY_PARAMETERS -11
# define NO_PARAMETERS -12
# define WRONG_NUMBER_FORMAT -13
# define NUMBER_EXCCED_INT_MAX -14
# define NUMBER_LOWER_THAN_INT_MIN -15
# define DUPLICATE_FOUND -16
# define ALREADY_SORTED -17
# define FAILED_MALLOC_ERR -21

/* Struct definition */

typedef struct s_node
{
	int				num;
	struct s_node	*next;
} t_node;

/* Input validation funciton */

bool	ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char *str);
int		ft_atoi(char *str, int *err);
int		validate_input(int argc, char **argv, t_node **a);

/* Linked lists functions */

t_node *ft_lstnew(int number);
void	ft_lstadd_back(t_node **lst, t_node *node);
void	ft_lstclear(t_node **lst);


#endif