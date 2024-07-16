#include "../includes/push_swap.h"

void	lst_add_back(t_node **lst, t_node *node)
{
	t_node	*tmp_node;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = node;
	else
	{
		tmp_node = *lst;
		*lst = node;
		node->next = tmp_node;
	}
}
