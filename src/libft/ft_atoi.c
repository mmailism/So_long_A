/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:08:12 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/04 15:45:35 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	unsigned int	num;
	signed char		sign;
	size_t			i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (! (48 <= str[i] && str[i] <= 57))
			return (num * sign);
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}

/*	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (((char)str[i] >= 9 && (char)str[i] <= 13) || (char)str[i] == ' ')
	{
		if ((char)str[i] == '-' || (char)str[i] == '+')
			i++;
		j++;
	}
	while ((char)str[i] >= 48 && (char)str[i] <= 57)
	{
		k = k * 10 + ((char)str[i++] - 48);
	}
	return (k);
}*/

/*#include <stdio.h>
int main()
{
	printf("%d", ft_atoi("---8765"));
}*/
