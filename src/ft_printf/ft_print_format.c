/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:08 by kpueankl          #+#    #+#             */
/*   Updated: 2023/11/06 17:21:37 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_nbrlen_base(int n, size_t base)
{
	ssize_t	i;

	i = 1;
	while (n >= (int)base)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	ft_putlongnbr(void)
{
	if (write(1, "-2147483648", 11) == -1)
		return (-1);
	return (11);
}

int	ft_print_nbr(int n, int fd)
{
	const char	*base = "0123456789";
	int			nbr_len;

	nbr_len = 0;
	if (n == -2147483648)
		return (ft_putlongnbr());
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		nbr_len++;
		n = n * (-1);
	}
	if (n >= 10)
	{
		if (ft_print_nbr((n / 10), fd) == -1)
			return (-1);
		if (ft_print_nbr((n % 10), fd) == -1)
			return (-1);
	}
	else
		if (write (fd, &base[n], 1) == -1)
			return (-1);
	nbr_len += ft_nbrlen_base(n, 10);
	return (nbr_len);
}
