/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:18:41 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/22 14:49:38 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_char(const char *str, int neg)
{
	long	num;
	long	prev;

	num = 0;
	while (*str >= 48 && *str <= 57)
	{
		prev = num;
		num = (num * 10) + (*str - 48);
		str++;
		if (num < prev)
		{
			if (neg == 1)
				return (-1);
			return (0);
		}
	}
	return (num);
}

long	ft_atoi_long(const char *str)
{
	long	neg;
	long	num;

	neg = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
		{
			neg = -1;
		}
		str++;
	}
	num = convert_char(str, neg);
	return (num * neg);
}