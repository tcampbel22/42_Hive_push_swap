/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:17:25 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/18 17:45:44 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_check(t_stack **stack, t_stack *top, char stack_flag)
{
	while (*stack != top)
	{
		if (stack_flag == 'a')
		{
			if (top->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		if (stack_flag == 'b')
		{
			if (top->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	shift_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	while (*a != cheapest && *b != cheapest->target)
	{
		if (cheapest->above_median && cheapest->target->above_median)
			rr(a, b, false);
		else if (!cheapest->above_median && !cheapest->target->above_median)
			rrr(a, b, false);
	}
	push_check(a, cheapest, 'a');
	push_check(b, cheapest->target, 'b');
	pb(b, a);
}

void	shift_b(t_stack **b, t_stack **a)
{
	push_check(a, (*b)->target, 'a');
	while (*b)
	{
		ft_printf("B -> [%d]\n", (*b)->content);
		*b = (*b)->next;
	}
	pa(a, b);
}
