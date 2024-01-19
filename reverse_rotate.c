/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:36:18 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/19 15:27:40 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack)
		return ;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
	{
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_a != cheapest && *stack_b != cheapest->target)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	index_stack(*stack_a);
	index_stack(*stack_b);
	ft_printf("rrr\n");
}
