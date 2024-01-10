/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:59:41 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/10 17:45:10 by tcampbel         ###   ########.fr       */
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
	if ((*a)->next->content < (*a)->content)
		sa(a);
}

void	sort_5(t_stack **a)
{
	int	max;
	t_stack	*last;

	max = stack_max(*a);
	last = ft_lastnode(*a);
	while (max != last->content)
	{
		ra(a);
	}
}
