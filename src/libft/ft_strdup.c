/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:10:41 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/04 19:10:53 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*alt;
	char	n;

	n = ft_strlen(s1) + 1;
	alt = (char *)malloc(sizeof(char) * n);
	if (!alt)
		return (NULL);
	return ((char *)ft_memcpy(alt, s1, n));
}

// #include <stdio.h>
// int main()
// {
// 	char	string[] = "hello!";

// 	printf("%s\n", strdup(string));
// 	printf("%s\n", ft_strdup(string));
// }
