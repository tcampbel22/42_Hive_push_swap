/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:04:41 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/19 13:30:56 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	if (str[1] != '\0' && (str[0] == '-' || str[0] == '+'))
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	dup_check(int num, t_stack *stack)
{
	while (stack)
	{
		if (stack->content == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	perror_free(t_stack **stack)
{
	if (stack)
		stackfree(stack);
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	free_str(char **argv)
{
	size_t	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}
