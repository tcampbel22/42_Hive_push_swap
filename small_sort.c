/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:59:41 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/12 17:14:31 by tcampbel         ###   ########.fr       */
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

void	pre_sort(t_stack **a, t_stack **b, int size)
{
	int		min;
	int		size_b;
	int		i;

	min = stack_min(*a);
	size_b = stacksize(*b);
	if (size == 4)
		i = 1;
	else
		i = 2;
	while (size_b != i)
	{
		size_b = stacksize(*b);
		if (min == (*a)->content)
			pb(b,a);
		else
		{
			rra(a);
			pre_sort(a, b, size);
		}
	}
	sort_3(a);
}


void sort_5(t_stack **a, t_stack **b)
{
	if (check_sort(*a))
		return ;
	pre_sort(a, b, 5);
	pb(a, b);
	pb(a, b);
}


void	sort_4(t_stack **a, t_stack **b)
{
	if (check_sort(*a))
		return ;
	pre_sort(a, b, 4);
	pb(a, b);
}
