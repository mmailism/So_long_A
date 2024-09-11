/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:43 by kpueankl          #+#    #+#             */
/*   Updated: 2023/11/06 17:06:43 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

ssize_t	ft_print_str(char *str)
{
	ssize_t	i;

	i = 0;
	if (str == NULL)
	{
		if (ft_put_str("(null)") == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_perc(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

int	print_format(const char sp, va_list ap)
{
	int	count;

	count = 0;
	if (sp == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (sp == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (sp == 'p')
		count += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (sp == 'd' || sp == 'i')
		count += ft_print_nbr(va_arg(ap, long long int), 1);
	else if (sp == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (sp == 'x' || sp == 'X')
		count += ft_print_hlx(va_arg(ap, unsigned int), sp);
	else if (sp == '%')
		count += ft_print_perc();
	else if (write(1, &sp, 1) == -1)
		return (-1);
	else
	{
		if (write(1, &sp, 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		tmp;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			tmp = print_format(*(++format), ap);
			if (tmp == -1)
				return (-1);
		}
		else
		{
			tmp = write(1, format, 1);
			if (tmp == -1)
				return (-1);
		}
		count += tmp;
		format++;
	}
	va_end(ap);
	return (count);
}
