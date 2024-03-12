/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:04:17 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:04:18 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned char	*to_ptr;
	unsigned char	*from_ptr;

	if (to == 0 && from == 0)
		return (0);
	to_ptr = (unsigned char *)to;
	from_ptr = (unsigned char *)from;
	while (n > 0 && n--)
	{
		(*to_ptr = *from_ptr);
		to_ptr++;
		from_ptr++;
	}
	return (to);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
    char i[] = "hello";
    char j[] = "goodbye";

//    printf("%s\n", ft_memcpy(i, j, sizeof(j)));
	printf("%s\n", ft_memcpy(((void *)0), ((void *)0), 3));
    return (0);
}*/
