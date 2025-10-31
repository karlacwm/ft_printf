/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheung <wcheung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:09:52 by wcheung           #+#    #+#             */
/*   Updated: 2025/10/31 11:45:39 by wcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_type(char specifier, va_list args)
{
	int	count;

	// cspdiuxX%
	// if % is found, select a type
	// va_arg(args, int);
	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(args, int));
	if (specifier == 's')
		count = print_str(va_arg(args, char *));
	if (specifier == 'p')
	if (specifier == 'd' || specifier == 'i')
		count = print_int(va_arg(args, int));
	if (specifier == 'u')
		count = print_unsigned(va_arg(args, int));
	if (specifier == 'x')
	if (specifier == 'X')
	if (specifier == '%')
	{
		ft_putchar_fd("%%", 1);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		total_count;
	va_list	args;

	if (!str)
		return (-1);
	total_count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			// if it's format specifier after, count printed length
		}
		else
		{
			ft_putchar_fd(*str, 1);
			total_count++;
		}
		str++;
	}
	va_end(args);
	return (total_count);
}
// count the total of how many characters are printed
