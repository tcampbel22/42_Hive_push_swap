/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:34:28 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/18 16:42:23 by tcampbel         ###   ########.fr       */
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

void	ra(t_stack **stack_a, t_bool check)
{
	rotate(stack_a);
	if (check)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, t_bool check)
{
	rotate(stack_b);
	if (check)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bool check)
{
	rotate(stack_a);
	rotate(stack_b);
	index_stack(*stack_a);
	index_stack(*stack_b);
	if (!check)
		ft_printf("rr\n");
}
