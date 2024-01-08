/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:59:13 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/08 16:05:31 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct s_stack
{
	int	content;
//	int	index;
	struct	s_stack *next;
}	t_stack;

void	ft_perror_free(t_stack **stack);
int		check_digit(char *str);
int		dup_check(int num, t_stack *stack);
void	fill_stack(t_stack **stack, char **argv, int split_check);
void	ft_lstfree(t_stack **stack);
t_stack	*ft_lastnode(t_stack *stack);
void	stack_append(t_stack **stack, int num);
int		ft_stacksize(t_stack *stack);
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
#endif
