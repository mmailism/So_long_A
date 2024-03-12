/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:10:09 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/04 19:10:26 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t n)
{
	void	*alt;

	alt = (void *)malloc(count * n);
	if (alt == NULL)
		return (NULL);
	ft_bzero(alt, (count * n));
	return (alt);
}

// #include <stdio.h>
// int main()
// {
// 	void	*ptrc;
// 	void	*ptrm;
// 	int		i;

// 	ptrc = calloc(3, 4);
// 	ptrm = malloc(12);
// 	i = 0;
// 	while (i < 12)
// 	{
// 		printf("%c__", ((char *)ptrm)[i] + 48);
// 		printf("%c\n", ((char *)ptrc)[i] + 48);
// 		i++;
// 	}
// }