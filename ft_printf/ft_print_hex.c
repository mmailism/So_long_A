/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:55:14 by kpueankl          #+#    #+#             */
/*   Updated: 2023/11/06 16:16:23 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hlx(unsigned int n, const char base)
{
	int	tmp;

	tmp = 0;
	if (n >= 16)
	{
		if (ft_put_hlx(n / 16, base) == -1)
			return (-1);
		if (ft_put_hlx(n % 16, base) == -1)
			return (-1);
	}
	else
	{
		if (n <= 9)
			tmp = ft_print_char(n + '0');
		else
		{
			if (base == 'x')
				tmp = ft_print_char(n - 10 + 'a');
			if (base == 'X')
				tmp = ft_print_char(n - 10 + 'A');
		}
	}
	if (tmp == -1)
		return (-1);
	return (0);
}

int	ft_print_hlx(unsigned int n, const char base)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		len++;
		return (len);
	}
	else
		if (ft_put_hlx(n, base) == -1)
			return (-1);
	return (ft_ptrlen(n));
}

void	ft_put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_print_char(n + '0');
		else
			ft_print_char(n - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long n)
{
	int	length;
	int	tmp;

	length = 0;
	tmp = write(1, "0x", 2);
	if (tmp == -1)
		return (-1);
	length += tmp;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		ft_put_ptr(n);
		length += ft_ptrlen(n);
	}
	return (length);
}

int	ft_print_unsigned(unsigned int n)
{
	if (ft_put_unsigned(n) == -1)
		return (-1);
	return (u_digits(n));
}
