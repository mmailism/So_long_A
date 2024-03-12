/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:07:28 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:07:34 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*alts1;
	const unsigned char	*alts2;
	size_t				i;

	alts1 = (const unsigned char *)str1;
	alts2 = (const unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (alts1[i] != alts2[i])
		{
			return (alts1[i] - alts2[i]);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	char	word1[] = "B";
	char	word2[] = "A";

	printf("%d\n", ft_memcmp(word1, word2, sizeof(char)));
}*/
