/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:18:51 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:18:53 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (s1 == 0)
		return (NULL);
	if (set == 0)
		return ((char *)(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j] && ft_strchr(set, s1[j]))
		j--;
	dst = ft_substr(s1, i, j - i + 1);
	return (dst);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_strtrim("			", " "));
// 	return (0);
// }
