/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailism <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:19:07 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/22 17:23:10 by mailism          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*al_word(const char *str, int start, int end)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (start < end)
	{
		dst[i] = str[start];
		i++;
		start++;
	}
	dst[i] = 0;
	return (dst);
}

static int	word_count(const char *str, char n)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*str)
	{
		if (*str != n && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*str == n)
			i = 0;
		str++;
	}
	return (count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static void	ft_numalt(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**altw;
	size_t	i;
	int		j;
	int		s_word;

	ft_numalt(&i, &j, &s_word);
	altw = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!altw || !s)
		return (NULL);
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			altw[j] = al_word(s, s_word, i);
			if (!(altw[j]))
				return (ft_free(altw, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (altw);
}

// #include <stdio.h>

// int main()
// {
// 	char	**tab;

// 	tab = ft_split("tripouille", 0);
// 	printf("%d\n", tab[1] == NULL);
// 	return (0);
// }
