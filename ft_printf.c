/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheung <wcheung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:09:52 by wcheung           #+#    #+#             */
/*   Updated: 2025/10/29 16:45:52 by wcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(char specifier, va_list args)
{
	// cspdiuxX%
	// if % is found, select a type
	// va_arg(args, int);
	if (specifier == 'c')
	{
		va_arg(args, int);
		//putchar
	}
	if (specifier == 's')
	{
		va_arg(args, char*);
		//putstr
	}
	if ( == '%')
	{
		// put %
	}
}

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args , str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
// count how many characters are printed
