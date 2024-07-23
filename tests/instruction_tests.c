#include "includes/push_swap.h"

/* void	check()
{
	system("leaks run")
} */

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a = (t_stack) {NULL, 0, A};
	b = (t_stack) {NULL, 0, B};
	validate_input(argc, argv, &a);
	index_stack(&a);
	b.top = ft_lstnew(-10);
	ft_lstadd_back(&(b.top), ft_lstnew(-2));


	ft_printf("---------------------------------------\n");
	t_node	*pass;

	ft_printf("----------- The stack layout ----------\n");
	pass = a.top;
	while (pass)
	{
		ft_printf("Number: %d --- Index: %u\n", pass->num, pass->index);
		pass = pass->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);
	ft_printf("---------------------------------------\n\n");

	
	ft_printf("---------- Used instructions ----------\n");
	ft_swap(&a);
	t_node	*pass2;

	ft_printf("----------- The stack layout ----------\n");
	pass2 = a.top;
	while (pass2)
	{
		ft_printf("Number: %d --- Index: %u\n", pass2->num, pass2->index);
		pass2 = pass2->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);
	ft_printf("---------------------------------------\n\n");


	ft_printf("---------- Used instructions ----------\n");
	ft_swap(&a);
	// ft_printf("---------------------------------------\n");
	t_node	*pass3;

	ft_printf("----------- The stack layout ----------\n");
	pass3 = a.top;
	while (pass3)
	{
		ft_printf("Number: %d --- Index: %u\n", pass3->num, pass3->index);
		pass3 = pass3->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);
	ft_printf("---------------------------------------\n\n");


	ft_printf("---------- Used instructions ----------\n");
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	t_node	*pass4;

	ft_printf("----------- The stack layout ----------\n");
	pass4 = a.top;
	while (pass4)
	{
		ft_printf("Number: %d --- Index: %u\n", pass4->num, pass4->index);
		pass4 = pass4->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);
	ft_printf("---------------------------------------\n\n");


	ft_printf("---------- Used instructions ----------\n");
	ft_rev_rotate(&a);

	t_node	*pass5;

	ft_printf("----------- The stack layout ----------\n");
	pass5 = a.top;
	while (pass5)
	{
		ft_printf("Number: %d --- Index: %u\n", pass5->num, pass5->index);
		pass5 = pass5->next;
	}
	ft_printf("The size of stack a is %u\n ", a.size);
	ft_printf("---------------------------------------\n\n");
	ft_lstclear(&a.top);
	ft_lstclear(&b.top);
}
