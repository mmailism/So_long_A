/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailism <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:07:58 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/21 15:52:59 by mailism          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (haystack == NULL && n == 0)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < n)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
    const char *string_b = "This is a sample string.";
    const char *string_a = "sample";
    size_t len = 0;

    const char *result = ft_strnstr(string_b, string_a, len);
    printf("Found substring: %s\n", result);
    return 0;
}*/
