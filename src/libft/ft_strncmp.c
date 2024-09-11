/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:06:47 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:06:49 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] == '\0' || str2[i] == '\0')
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		else if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	char	word1[] = "BA";
	char	word2[] = "A";
	int		size	= 1;

	printf("%d\n", strncmp(word1, word2, size));
	printf("%d\n", ft_strncmp(word1, word2, size));
}*/
