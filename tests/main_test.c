#include "../includes/push_swap.h"
#include <stdio.h>
#include "test.h"

void leaks_check()
{
	system("leaks run");
	printf("-------------------------------------------------------\n");
}

int main()
{
	// t_node	node1;
	// t_node	node2;
	// t_node	node3;
	atexit(leaks_check);

	// node2 = (t_node) {4, NULL};
	// node1 = (t_node) {3, &node2};
	// node3 = (t_node) {5, NULL};
	// t_node	*pass = &node1;
	// t_node	*pass2 = &node1;
	// t_node	**lst = &pass2;
	// while(pass)
	// {
	// 	printf("|%d|\n", pass->num);
	// 	pass = (pass)->next;
	// }
	// printf("-------------------------------------------------------\n");
	// lst_add_back(lst, &node3);
	// while((*lst))
	// {
	// 	printf("|%d|\n", (*lst)->num);
	// 	(*lst) = ((*lst))->next;
	// }
	// printf("-------------------------------------------------------\n");
	// printf("node3's next address: %p\n", node3.next);
	// printf("node2's address: %p\n", &node1);
	// while (1)
	// 	;
	
	t_list	*node = ft_lstnew("yo");

	printf("|%s|\n", node->data);
	free(node);
	printf("-------------------------------------------------------\n");
}
