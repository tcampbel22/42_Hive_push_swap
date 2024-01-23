/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:31:44 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 13:43:11 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (!dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		*dest = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, t_bool check)
{
	push(a, b);
	if (!check)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, t_bool check)
{
	push(b, a);
	if (!check)
		ft_printf("pb\n");
}
