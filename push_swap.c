/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:27:42 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/12 16:58:26 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{ 
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		split_check;

	stack_a = NULL;
	stack_b = NULL;
	split_check = 0;

	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		if (!argv[1])
			return (0);
		split_check = 1;
		argv = ft_split(argv[1], ' ');
	}
	fill_stack(&stack_a, argv, split_check);
	if (!&fill_stack)
		perror_free(&stack_a);
	if (stacksize(stack_a) > 1 && stacksize(stack_a) < 4)
	{
		sort_3(&stack_a);
		if (check_sort(stack_a))
			ft_printf("Great Success!\n");
		else
			ft_printf("Sorting Failed BOOOOOOO!\n");
		while (stack_a)
		{
			ft_printf("%d\n", stack_a->content);
			stack_a = stack_a->next;
		}
	}
	if (stacksize(stack_a) == 5)
	{
		sort_5(&stack_a, &stack_b);
		while (stack_a)
		{
			while (stack_b)
			{
				ft_printf("B->%d\n", stack_b->content);
				stack_b = stack_b->next;
			}
			ft_printf("A->%d\n", stack_a->content);
			stack_a = stack_a->next;
		}
	}
	if (stacksize(stack_a) == 4)
	{
		sort_4(&stack_a, &stack_b);
		while (stack_a)
		{
			while (stack_b)
			{
				ft_printf("B->%d\n", stack_b->content);
				stack_b = stack_b->next;
			}
			ft_printf("A->%d\n", stack_a->content);
			stack_a = stack_a->next;
		}
	}
	stackfree(&stack_b);
	stackfree(&stack_a);
	return(0);
}
