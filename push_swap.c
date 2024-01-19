/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:27:42 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/19 15:46:33 by tcampbel         ###   ########.fr       */
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
	else if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		split_check = 1;
		argv = ft_split(argv[1], ' ');
	}
	fill_stack(&stack_a, argv, split_check);
	if (!&fill_stack)
	{
		perror_free(&stack_a);
		free_str(argv);
	}
	if (!check_sort(stack_a))
	{
		if (stacksize(stack_a) == 2 || stacksize(stack_a) == 3)
			sort_three(&stack_a);
		else
			big_sort(&stack_a, &stack_b);
	}
//	if (check_sort(stack_a))
//		ft_printf("Sorted");
	stackfree(&stack_a);
	stackfree(&stack_b);
	return(0);
}
