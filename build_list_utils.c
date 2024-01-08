/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:25:06 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/08 16:12:53 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
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

void	ft_lstfree(t_stack **stack)
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

t_stack *ft_lastnode(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
//modified lst_addback and lstnew
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
		last_node = ft_lastnode(*stack);
		last_node->next = new_node;
	}
	ft_printf("Node before -> %d\n", new_node->content);
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
			ft_perror_free(stack);
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			ft_perror_free(stack);
		if (!dup_check(num, *stack))
			ft_perror_free(stack);
		stack_append(stack, (int)num);
		i++;
		}
}
