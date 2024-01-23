/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:22:54 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 14:30:19 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stacksize(a);
	len_b = stacksize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = len_a - a->index;
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	int		cheapest;
	t_stack	*cheapest_node;

	cheapest = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*find_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (0);
}

void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*temp_b;
	t_stack	*target_node;
	int		closest;

	while (a)
	{
		temp_b = b;
		closest = INT_MIN;
		a->target = stack_max(b);
		while (temp_b)
		{
			if (temp_b->content < a->content && temp_b->content >= closest)
			{
				closest = temp_b->content;
				target_node = temp_b;
				a->target = target_node;
			}
			temp_b = temp_b->next;
		}
		a = a->next;
	}
}

void	init_stack_a(t_stack *a, t_stack *b)
{
	index_stack(a);
	index_stack(b);
	target_a(a, b);
	set_cost(a, b);
	set_cheapest(a);
}
