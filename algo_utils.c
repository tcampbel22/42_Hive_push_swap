/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:43 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 14:27:39 by tcampbel         ###   ########.fr       */
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
		if (index <= median)
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
		exit(false);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}

void	target_b(t_stack *b, t_stack *a)
{
	t_stack	*temp_a;
	t_stack	*target_node;
	int		closest;

	while (b)
	{
		temp_a = a;
		closest = INT_MAX;
		b->target = stack_min(a);
		while (temp_a)
		{
			if (temp_a->content > b->content && temp_a->content <= closest)
			{
				closest = temp_a->content;
				target_node = temp_a;
				b->target = target_node;
			}
			temp_a = temp_a->next;
		}
		b = b->next;
	}
}

void	final_sort(t_stack **a)
{
	t_stack	*min;

	min = stack_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	init_stack_b(t_stack *b, t_stack *a)
{
	index_stack(a);
	index_stack(b);
	target_b(b, a);
}
