/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:27:42 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/22 15:51:02 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_perror(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 3)
		return (0);

	while (argv[i])
	{
		if (argv[i][1] != '\0' && (argv[i][0] == '-' || argv[i][0] == '+'))
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	
	i = 1;
	while (argv[i])
	{
		if (ft_atoi_long(argv[i]) > 2147483647 || ft_atoi_long(argv[i]) < -2147483648) 
		{
			return (0);
		}
		i++;
	}
/*	i = 0;
	while (argv[i])
	{
		if (!strncmp(argv[i][j])
				return (0);
		j++;
		i++;
	}*/
	return (1);
}

int	main(int argc, char **argv)
{
//	int	argc = 3;
//	char *argv[2] = {"13", "5"}; 
	if (ft_perror(argc, argv) == 0)
		ft_putendl_fd("Error", 2);
	else
		ft_printf("Great Success!");

	return(0);
}
