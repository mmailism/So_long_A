/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:01:48 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 17:56:58 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"*/

int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	ft_isdigit(int i);

int     main()
{
        printf("%d\n", ft_isdigit('1'));
        return (0);
}*/
