/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:43 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/18 17:41:19 by tcampbel         ###   ########.fr       */
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
		exit(0);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
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
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		ft_printf("Node ->[%d] Cost->[%d] Target->[%d]\n", a->content, a->push_cost, a->target->content);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	int	cheapest;
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

void	target_b(t_stack *b, t_stack *a)
{
	t_stack	*temp_a;
	t_stack	*target_node;
	long	closest;

	while (b)
	{
		temp_a = a;
		closest = INT_MAX;
		b->target = stack_min(a);
		while (temp_a)
		{
			if (b->content < temp_a->content && temp_a->content <= closest)
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

void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*temp_b;
	t_stack	*target_node;
	long	closest;

	while (a)
	{
		temp_b = b;
		closest = INT_MIN;
		a->target = stack_max(b);
		while (temp_b)
		{
			if (a->content > temp_b->content && temp_b->content <= closest)
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

void	final_sort(t_stack **a)
{
	t_stack	*min;

	min = stack_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	init_stack_a(t_stack *a, t_stack  *b)
{
	index_stack(a);
	index_stack(b);
	target_a(a, b);
	set_cost(a, b);
	set_cheapest(a);
}

void	init_stack_b(t_stack *b, t_stack  *a)
{
	index_stack(a);
	index_stack(b);
	target_b(b, a);
}
