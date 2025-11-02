/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheung <wcheung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:09:52 by wcheung           #+#    #+#             */
/*   Updated: 2025/11/02 21:43:07 by wcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cspdiuxX%
// if % is found, select a type
// va_arg(args, int);
// char str[]= "aaaa";
// printf("%s %d %p", str);

#include "ft_printf.h"

int	ft_type(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(args, int));
	if (specifier == 's')
		count = print_str(va_arg(args, char *));
	if (specifier == 'p')
		count = print_pointer(va_arg(args, void *));
	if (specifier == 'd' || specifier == 'i')
		count = print_int(va_arg(args, int));
	if (specifier == 'u')
		count = print_unsigned_int(va_arg(args, unsigned int));
	if (specifier == 'x')
		count = print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	if (specifier == 'X')
		count = print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (specifier == '%')
		count = print_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		total_count;
	// where is my count
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
			if (ft_strchr("cspdiuxX%", *str))
				ft_type(*str);
		}
		else
		{
			ft_putchar_fd(*str, 1); //cant use fd...
			total_count++;
		}
		str++;
	}
	va_end(args);
	return (total_count);
}
// count the total of how many characters are printed
