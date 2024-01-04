/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:59:13 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/04 12:18:34 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct s_stack
{
	int	*content;
	struct	s_stack *next;
}	t_stack;

int	ft_perror(int argc, char **argv);
int	check_digit(char **str);
int	dup_check(char **str);


#endif
