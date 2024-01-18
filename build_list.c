/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:25:06 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/18 16:21:55 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack *stack)
{
	size_t	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	stackfree(t_stack **stack)
{
	t_stack *current;
	t_stack *prev;

	current = *stack;
	if (!stack)
		return ;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	*stack = NULL;
}

t_stack *lastnode(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_append(t_stack **stack, int num)
{
	t_stack *new_node;
	t_stack *last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = num;
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = lastnode(*stack);
		last_node->next = new_node;
	}
}

void	fill_stack(t_stack **stack, char **argv, int split_check)
{
	int		i;
	long	num;

	if (split_check == 1)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		if (!check_digit(argv[i]))
			perror_free(stack);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			perror_free(stack);
		if (!dup_check(num, *stack))
			perror_free(stack);
		stack_append(stack, (int)num);
		i++;
		}
}
