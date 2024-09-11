/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:04:50 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:04:54 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n - 1)
		{
			if (src[i] == '\0')
				break ;
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*#include <stdio.h>
#include <string.h>

int main()
{
    char destination[20] = "Hello, ";
    char source[] = "world!";

    size_t copied_len = ft_strlcpy(destination, source, sizeof(destination));

    printf("Copied string: %s\n", destination);
    printf("Length of copied string: %zu\n", copied_len);

    return 0;
}*/
