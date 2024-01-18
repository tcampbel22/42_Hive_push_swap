/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:11:59 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/18 12:19:41 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_max(t_stack *stack)
{
	t_stack	*max;
	int		temp;

	temp = INT_MIN;
	while (stack)
	{
		if (stack->content > temp)
		{
			temp = stack->content;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack	*min;
	int		temp;

	temp = INT_MAX;
	while (stack)
	{
		if (stack->content < temp)
		{
			temp = stack->content;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}
