/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheung <wcheung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:09:52 by wcheung           #+#    #+#             */
/*   Updated: 2025/10/30 15:32:53 by wcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_str(char *str)
{
	if (!str)
		return (0);
	else
		ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_int(int n)
{
	char	*a;
	size_t	digits;

	a = ft_itoa(n);
	ft_putstr_fd(a, 1);
	digits = ft_strlen(a);
	free(a);
	return (digits);
}

int	print_unsigned()


int	ft_type(char specifier, va_list args)
{
	// cspdiuxX%
	// if % is found, select a type
	// va_arg(args, int);

	int	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(args, int));
	if (specifier == 's')
		count = print_str(va_arg(args, char*));
	if (specifier == 'p')
	if (specifier == 'd' || specifier == 'i')
		count = print_int(va_arg(args, int));
	if (specifier == 'u')
	if (specifier == 'x')
	if (specifier == 'X')
	if (specifier == '%')
		// put %
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	total_count;
	va_list	args;

	if (!str)
		return (-1);
	total_count = 0;
	va_start(args , str);
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

// void	ft_hexadecimal(unsigned char c)
// {
// 	char	*hex;

// 	hex = "0123456789abcdef";
// 	write(1, &hex[c / 16], 1);
// 	write(1, &hex[c % 16], 1);
// }
