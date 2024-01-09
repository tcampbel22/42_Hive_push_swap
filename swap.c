/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:00 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/09 16:12:50 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first 2 elements in stack a
void	swap(t_stack **stack)
{
	t_stack *temp;

	if (ft_stacksize(*stack) < 2 || !*stack || !stack)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	ft_printf("\n");
	while (*stack)
	{
		ft_printf("Node after swap-> %d\n", (*stack)->content);
		*stack = (*stack)->next;
	}
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

//swap the first 2 elements in stack b
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

//swap_a and swap b at the same time
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
