/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheung <wcheung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:09:52 by wcheung           #+#    #+#             */
/*   Updated: 2025/11/03 15:54:54 by wcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cspdiuxX%
// if % is found, select a type
// va_arg(args, int);
// char str[]= "aaaa";
// printf("%s %d %p", str);

#include "ft_printf.h"

static int	ft_type(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(args, int));
	else if (specifier == 's')
		count = print_str(va_arg(args, char *));
	// else if (specifier == 'p')
	// 	count = print_pointer();
	else if (specifier == 'd' || specifier == 'i')
		count = print_int(va_arg(args, int));
	else if (specifier == 'u')
		count = print_unsigned_int(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count = print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		count = print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (specifier == '%')
		count = print_char('%');
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
			if (ft_strchr("cspdiuxX%", *str))
				total_count += ft_type(*str, args);
		}
		else
		{
			write(1, str, 1);
			total_count++;
		}
		str++;
	}
	va_end(args);
	return (total_count);
}
// count the total of how many characters are printed
