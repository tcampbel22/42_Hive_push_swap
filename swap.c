/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:00 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 13:53:12 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (stacksize(*stack) < 2 || !*stack || !stack)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack **a, t_bool check)
{
	swap(a);
	if (!check)
		ft_printf("sa\n");
}

void	sb(t_stack **b, t_bool check)
{
	swap(b);
	if (!check)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, t_bool check)
{
	swap(a);
	swap(b);
	if (!check)
		ft_printf("ss\n");
}

void	swap_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		ss(a, b, false);
	index_stack(*a);
	index_stack(*b);
}
