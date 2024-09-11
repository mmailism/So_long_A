/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:07:06 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:07:07 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)str;
	i = 0;
	while (n > i)
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int main()
{
    unsigned char wrd[] = "abcdef";

   printf("%s\n", (char *)ft_memchr(wrd, 'd', sizeof(wrd)));
   return (0);
}*/
