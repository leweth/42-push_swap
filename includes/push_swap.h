/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:14:36 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/20 20:31:29 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "../includes/ft_printf.h"

# define SUCCESS 0
# define FAILURE -1

/* STack names */

# define A 23
# define B 24

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

typedef struct s_stack
{
	t_node			*top;
	unsigned int	size;
	int				type;
} t_stack;

/* Input validation funciton */

bool	ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char *str);
int		ft_atoi(char *str, int *err);
int		validate_input(int argc, char **argv, t_stack *a);

/* Linked lists functions */

t_node *ft_lstnew(int number);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *node);
void	ft_lstclear(t_node **lst);

/* Instructions implementaion functions */
void	ft_swap(t_stack *stack);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_push(t_stack *stack1, t_stack *stack2);
void	ft_rotate(t_stack *stack);
void	recursive_rotate(t_stack *stack);
void	ft_rev_rotate(t_stack *stack);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

/* Sort utils */
void	ft_sort(t_stack *a, t_stack *b);
void	mins_of_stack(t_stack *stack, int *min1, int *min2);
void 	ft_sort_more(t_stack *stack);
void 	set_in_top(t_stack	*stack, int pos);
int		ft_min(t_stack *stack, int *min);

#endif