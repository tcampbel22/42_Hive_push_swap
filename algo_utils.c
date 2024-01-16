/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:43 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/16 16:58:07 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack	*stack)
{
	int	index;
	int	median;

	index = 0;
	median = stacksize(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index >= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		index++;
	}
}

t_bool	check_sort(t_stack *a)
{
	if (!a)
		exit(0);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}

void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*temp_b;
	t_stack	*target;
	long	closest;

	while (a)
	{
		temp_b = b;
		closest = LONG_MAX;
		while (b)
		{
			if (a->content > temp_b->content && temp_b->content < closest)
			{
				closest = temp_b->content;
				target = temp_b;
			}
			b = b->next;
		}
		a = a->next;
		if (closest == LONG_MAX)
			a->target = stack_max(b);
		else
			a->target = target;
	}
}

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
		if (a->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	int	cheapest;
	t_stack	*cheapest_node;
	
	cheapest = INT_MIN;
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


void	init_stack(t_stack *a, t_stack  *b)
{
	index_stack(a);
	index_stack(b);
	target_a(a, b);
	set_cost(a, b);
	set_cheapest(a);
}
