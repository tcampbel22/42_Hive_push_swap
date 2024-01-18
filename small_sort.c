/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:59:41 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/18 12:19:58 by tcampbel         ###   ########.fr       */
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
		ra(a, true);
	else if (max->content == (*a)->next->content)
		rra(a, true);
	if ((*a)->content > (*a)->next->content)
		sa(a, true);
}
