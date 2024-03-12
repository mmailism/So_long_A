/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:04:01 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/04 16:44:37 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*i;
	size_t			j;

	i = s;
	j = 0;
	if (n == 0)
		return ;
	while (j < n)
	{
		i[j] = 0;
		j++;
	}
}

/*#include <stdio.h>

int main()
{
    char str1[] = "stray kids";
    char str2[] = "";

    ft_bzero(str1, 0);
    printf("str1: %s\n");
    ft_bzero(str2, 0);s
	printf("str2: %s\n");
	return (0);
}*/
