/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:27:42 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/21 16:47:10 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_perror(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc < 3)
		return (0);

	while (argv[i])
	{
		if (ft_atoi(*argv) == 0 || ft_atoi(*argv) == -1) 
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (!ft_perror(argc, *argv[]))
		ft_printf("Error\n");

	return(0);
}
