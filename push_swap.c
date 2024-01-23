/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:27:42 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 14:50:04 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		split_check;

	a = NULL;
	b = NULL;
	split_check = 0;
	if (argc < 2)
		return (0);
	else if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		split_check = 1;
		argv = ft_split(argv[1], ' ');
	}
	fill_stack(&a, argv, split_check);
	if (!&fill_stack)
	{
		perror_free(&a);
		free_str(argv);
	}
	pre_sort(&a, &b);
	stackfree(&a);
	stackfree(&b);
	return (0);
}
