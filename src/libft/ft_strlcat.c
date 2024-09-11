/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:05:13 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:05:15 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	if (!dst && !src)
		return (0);
	if (!size)
		return (ft_strlen(src) + size);
	s = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	d = i;
	while (src[i - d] && i < size - 1)
	{
		dst[i] = src[i - d];
		i++;
	}
	if (d < size)
		dst[i] = '\0';
	return (d + s);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
    char dest[] = "pqrstuvwxyz";
    const char *src = "abcd";
    size_t result = ft_strlcat("pqrstuvwxyz", "abcd", 0);
    printf("Resulting string: %s\n", dest);
    printf("Total characters written: %zu\n", result);

    	return 0;
}*/
