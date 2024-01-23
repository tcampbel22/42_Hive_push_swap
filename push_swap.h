/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:59:13 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/23 14:33:01 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_stack
{
	int				content;
	int				index;
	int				push_cost;
	t_bool			cheapest;
	t_bool			above_median;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

void	perror_free(t_stack **stack);
void	free_str(char	**argv);
int		check_digit(char *str);
int		dup_check(int num, t_stack *stack);
void	fill_stack(t_stack **stack, char **argv, int split_check);
void	stackfree(t_stack **stack);
t_stack	*lastnode(t_stack *stack);
void	stack_append(t_stack **stack, int num);
int		stacksize(t_stack *stack);
void	swap(t_stack **stack);
void	sa(t_stack **a, t_bool check);
void	sb(t_stack **b, t_bool check);
void	ss(t_stack **a, t_stack **b, t_bool check);
void	push(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b, t_bool check);
void	pb(t_stack **a, t_stack **b, t_bool check);
void	rotate(t_stack **stack);
void	ra(t_stack **a, t_bool check);
void	rb(t_stack **b, t_bool check);
void	rr(t_stack **a, t_stack **b, t_bool check);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, t_bool check);
void	rrb(t_stack **b, t_bool check);
void	rrr(t_stack **a, t_stack **b, t_bool check);
t_stack	*stack_min(t_stack *stack);
t_stack	*stack_max(t_stack *stack);
void	sort_three(t_stack **a);
t_bool	check_sort(t_stack *a);
void	index_stack(t_stack *stack);
void	target_a(t_stack *a, t_stack *b);
void	index_stack(t_stack *stack);
void	init_stack_a(t_stack *a, t_stack *b);
void	init_stack_b(t_stack *b, t_stack *a);
void	big_sort(t_stack **a, t_stack **b);
void	set_cheapest(t_stack *stack);
void	set_cost(t_stack *a, t_stack *b);
t_stack	*find_cheapest(t_stack *stack);
void	shift_a(t_stack **a, t_stack **b);
void	shift_b(t_stack **b, t_stack **a);
void	push_check(t_stack **stack, t_stack *top, char stack_flag);
void	target_b(t_stack *b, t_stack *a);
void	final_sort(t_stack **a);
void	swap_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	reverse_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	pre_sort(t_stack **a, t_stack **b);
#endif
