/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:36:18 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/08 16:13:38 by tcampbel         ###   ########.fr       */
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
		ft_printf("Node after -> %d\n", (*stack)->content);
		*stack = (*stack)->next;
	}
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
/*	while (*stack_a)
	{
		ft_printf("Node -> %d", stack_a->content);
		*stack_a = *stack_a->next;
	}*/
}
/*
//swap the first 2 elements in stack b
void	sb(char **stack_b)
{

	ft_printf("sb\n");
}

//swap_a and swap b at the same time
void	ss(char **stack_a, char **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

//take the top element of stack b and put it top of stack a
void	pa(char *stack_a, char *stack_b)
{
	
	ft_printf("pa\n");
}

//take the top element of stack a and put it top of stack b
void	pb(char *stack_a, char *stack_b)
{
	ft_printf("pb\n");
}

//shift all elements of stack_a up by 1
void	ra(char *stack_a)
{

	ft_printf("ra\n");
}

//shift all elements of stack b up by 1
void	rb(char *stack_b)
{

	ft_printf("rb\n");
}

//ra and rb at the same time
void	rr(char *stack_a, char *stack_b)
{
	ra(stack_a);
	rb(stack_b;
	ft_printf("rr\n");
}

//shift all elements of stack a down by 1
void	rra(char *stack_a)
{

	ft_printf("rra\n");
}

//shift all elements of stack b down by 1
void	rrb(char *stack_b)
{
	ft_printf("rrb\n");
}

//rra and rrb at the same time
void	rrr(char *stack_a, char *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
*/
