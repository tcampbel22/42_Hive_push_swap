/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:27:42 by tcampbel          #+#    #+#             */
/*   Updated: 2024/01/02 18:21:12 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (str[i][1] != '\0' && (str[i][0] == '-' || str[i][0] == '+'))
			j++;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	i = 1;
	while (str[i])
	{
		if (ft_atoi_long(str[i]) < -2147483648 || ft_atoi_long(str[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int dup_check(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strncmp(str[i], str[i], ft_strlen(str[i])) == 0)
		{
			ft_printf("%d\n", ft_strncmp(str[i], str[i], ft_strlen(str[i])));
			return (0);
		}
		i++;
	}
	return (1);
}
int ft_perror(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	j = 0;
	if (argc == 2)
	{
		if (!argv[1] || !ft_strchr(argv[1], ' '))
			return (0);
		split = ft_split(argv[1], ' '); 
		i = 0;
		while (split[i])
			ft_printf("%s\n", split[i++]);
		if (!check_digit(split) || !dup_check(split))
			return (0);
	}
	else if (!check_digit(argv) || !dup_check(argv))
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{ 
	if (argc < 2)
		return (0);
	if (ft_perror(argc, argv) == 0)
		ft_putendl_fd("Error", 2);
	else
		ft_printf("Great Success!");
	return(0);
}
