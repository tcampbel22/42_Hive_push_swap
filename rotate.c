/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:34:28 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 13:53:29 by tcampbel         ###   ########.fr       */
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

void	ra(t_stack **a, t_bool check)
{
	rotate(a);
	if (!check)
		ft_printf("ra\n");
}

void	rb(t_stack **b, t_bool check)
{
	rotate(b);
	if (!check)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, t_bool check)
{
	rotate(a);
	rotate(b);
	if (!check)
		ft_printf("rr\n");
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b, false);
	index_stack(*a);
	index_stack(*b);
}
