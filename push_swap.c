/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:27:42 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/05 18:17:04 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	if (str[1] != '\0' && (str[0] == '-' || str[0] == '+'))
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int dup_check(int num, t_stack *stack)
{
	while (stack)
	{
		if (stack->content == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void ft_perror_free(t_stack **stack)
{
	if (stack)
		ft_lstfree(stack);
	ft_putendl_fd("Error", 2);
	exit(0);
}


int	main(int argc, char **argv)
{ 
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		split_check;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	split_check = 0;
	i = 0;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!argv[1])
			return (0);
		argv = ft_split(argv[1], ' ');
		split_check = 1;
	}
	fill_stack(&stack_a, argv, split_check);
	/*while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
		ft_printf("Inside node [%d] -> %d\n", i, stack_a->content);
	}*/
	ft_printf("Great Success!");
	return(0);
}
