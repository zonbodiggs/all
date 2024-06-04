#include "push_swap.h"

void  print_stack(t_stack *stack_a, t_stack *stack_b, int argc)
{
	t_stack	*max = find_max(stack_a);
	t_stack	*min = find_min(stack_a);
	ft_printf("\033[0;33m");
	ft_printf("MAX :%d\n", max -> content);
	ft_printf("MIN :%d\n", min -> content);
	ft_printf("\033[0;35m");
	ft_printf("LEN :%d\n\n", ft_lstsize(stack_a));
	ft_printf("\033[0;37m");
	if (is_stack_sort(stack_a))
	{
		ft_printf("\033[0;32m");
		ft_printf("\n---congratulation you're passed the test---\n");
	}
	else
	{
		ft_printf("\033[0;31m");
		ft_printf("\n---you suck bitch---\n");
	}
	ft_printf("\033[0;35m");
	ft_printf("\n---------------------STACK A ------------------------\n\n");
	if (argc > 1)
	{
		ft_printf("\033[0;37m");
		while (stack_a != NULL)
		{
			if (stack_a -> content)
			{	
				ft_printf("CONTENT A : %d\n", stack_a -> content);
				ft_printf("INDEX A : %d\n", stack_a -> index);
				ft_printf("POS A : %d\n", stack_a -> position);
				ft_printf("IS BIGGEST %d\n", stack_a->biggest);
			}
			if (stack_a->target)
				ft_printf("TARGET %d\n", stack_a->target->content);
			if (stack_a -> prev)
				ft_printf("PREV A IS : %d\n", stack_a -> prev -> content);
			if (stack_a -> next)
				ft_printf("NEXT A IS : %d\n", stack_a -> next -> content);
			ft_printf("\n\n -------- \n\n");
			stack_a = stack_a -> next;
	
		}
		ft_printf("\033[0;35m"); 
		ft_printf("\n---------------------STACK B ------------------------\n\n");
		ft_printf("\033[0;37m");
		while (stack_b != NULL)
		{
			if (stack_b -> content)
			{
				ft_printf("CONTENT B : %d\n", stack_b -> content);
				ft_printf("INDEX B : %d\n", stack_b -> index);
				ft_printf("POS B : %d\n", stack_b -> position);
				ft_printf("IS BIGGEST %d\n", stack_b->biggest);
			}
			if (stack_b -> prev)
				ft_printf("PREV B IS %d\n", stack_b -> prev -> content);
			if (stack_b -> next)
				ft_printf("NEXT B IS %d\n", stack_b -> next -> content);
			if (stack_b -> target)
				ft_printf("TARGET B IS %d\n", stack_b -> target -> content);
			ft_printf("\n\n -------- \n\n");
			stack_b = stack_b -> next;
		}
	}

}