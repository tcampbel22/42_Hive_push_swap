/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:59:41 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 13:55:15 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = stack_max(*a);
	if (!a)
		exit(0);
	if (max->content == (*a)->content)
		ra(a, false);
	else if (max->content == (*a)->next->content)
		rra(a, false);
	if ((*a)->content > (*a)->next->content)
		sa(a, false);
}
