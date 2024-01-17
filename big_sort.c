/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:51:25 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/17 17:33:11 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = stacksize(*a);
	if (len > 3 && !check_sort(*a))
	{
		len--;
		pb(b, a);
	}
	if (len > 3 && !check_sort(*a))
	{
		len--;
		pb(b, a);
	}
	while (len > 3)
	{
		init_stack_a(*a, *b);
		shift_a(a, b);
		len--;
	}
	sort_three(a);
	while (*b)
	{
		init_stack_b(*b, *a);
		shift_b(b, a);
	}
	index_stack(*a);
	final_sort(a);
}

