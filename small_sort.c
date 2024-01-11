/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:59:41 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/11 16:47:54 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	int	max;

	max = stack_max(*a);
	if (!a)
		exit(0);
	if (max == (*a)->content)
		ra(a);
	else if (max == (*a)->next->content)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

int	check_sort(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	min;
	t_stack	*last;

	min = stack_min(*a);
	last = ft_lastnode(*a);
	if (min == (*a)->content)
		pb(b,a);
	else
	{
		rra(a);
		sort_5(a, b);
	}
}
