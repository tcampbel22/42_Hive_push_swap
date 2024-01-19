/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:00 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/19 15:27:42 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (stacksize(*stack) < 2 || !*stack || !stack)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (!cheapest && !cheapest->target)
	{
		swap(stack_a);
		swap(stack_b);
	}
	index_stack(*stack_a);
	index_stack(*stack_b);
	ft_printf("ss\n");
}
