/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:06:32 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:06:34 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*size_t 	ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (*str != '\0')
    {
        str++;
        i++;
    }
	return (i);
}*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = len;
	while (i < len + 1)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*#include <stdio.h>

int main()
{
	printf("%s\n", ft_strrchr("stray kids stay", 's'));
	printf("%s\n", ft_strrchr("\0stray kids\0", '\0'));
	return 0;
}*/