/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:17:25 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 14:23:12 by tcampbel         ###   ########.fr       */
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
				ra(stack, false);
			else
				rra(stack, false);
		}
		if (stack_flag == 'b')
		{
			if (top->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	shift_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		reverse_both(a, b, cheapest);
	push_check(a, cheapest, 'a');
	push_check(b, cheapest->target, 'b');
	pb(b, a, false);
}

void	shift_b(t_stack **b, t_stack **a)
{
	push_check(a, (*b)->target, 'a');
	pa(a, b, false);
}
