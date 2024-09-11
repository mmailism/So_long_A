/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:04:31 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:04:33 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dst;
	s = (unsigned char *)src;
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	if (dst > src)
	{
		while (n--)
			d[n] = s[n];
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
    char i[] = "hello";
    char j[] = "goodbye";

    printf("%s\n", ft_memmove(i, j, sizeof(j)));
    return (0);
}*/
