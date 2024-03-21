/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:39:14 by kpueankl          #+#    #+#             */
/*   Updated: 2023/11/06 17:22:09 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		count;
	int		n;
	int		i;
	char	j;
	int		k;

	n = 100;
	i = 127;
	j = -1;
	k = -1;
	count = ft_printf("abc%s\n", "def");
	ft_printf("count : %d, char : %c, ascii char : %i\n", count, n, n);
	ft_printf("big %X and small %x and percent %%\n", i, i);
	ft_printf("address : %p %p\n", "m", NULL);
	write(1, "\n", 1);
	write(1, "and", 3);
	write(1, "\n\n", 2);
	count = printf("abc%s\n", "def");
	printf("count : %d, char : %c, ascii char : %i\n", count, n, n);
	printf("big %X and small %x and percent %%\n", i, i);
	printf("address : %p %p\n", "m", NULL);
	return (0);
}
