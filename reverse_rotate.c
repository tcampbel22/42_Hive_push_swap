/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:36:18 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 13:39:38 by tcampbel         ###   ########.fr       */
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

void	rra(t_stack **a, t_bool check)
{
	reverse_rotate(a);
	if (!check)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, t_bool check)
{
	reverse_rotate(b);
	if (!check)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, t_bool check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!check)
		ft_printf("rrr\n");
}

void	reverse_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b, false);
	index_stack(*a);
	index_stack(*b);
}
