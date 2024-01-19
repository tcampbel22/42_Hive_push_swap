/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:34:28 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/19 15:27:37 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	last = lastnode(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_a != cheapest && *stack_b != cheapest->target)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	index_stack(*stack_a);
	index_stack(*stack_b);
	ft_printf("rr\n");
}
