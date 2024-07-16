#include "../includes/push_swap.h"
#include <stdio.h>
#include "test.h"

t_list *ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *) malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->data = content;
	tmp->next = NULL;
	return (tmp);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void 	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return (NULL);
	del(lst->data);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_node	*tmp;

	if (!lst || !del)
		return (NULL);
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->data);
		free(*lst);
		*lst = tmp;
	}
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	void	*content;
	t_list	*ret;

	if (!lst || !f || !del)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		content = f(lst->data);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, node);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
}
