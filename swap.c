/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:00 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/17 15:16:00 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first 2 elements in stack a
void	swap(t_stack **stack)
{
	t_stack *temp;

	if (stacksize(*stack) < 2 || !*stack || !stack)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

//swap the first 2 elements in stack b
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

//swap_a and swap b at the same time
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
