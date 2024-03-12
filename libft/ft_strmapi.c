/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailism <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:20:01 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/21 15:16:50 by mailism          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*n;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	n = (char *)malloc(i + 1);
	if (n == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		n[i] = (*f)(i, s[i]);
		i++;
	}
	n[i] = 0;
	return (n);
}
