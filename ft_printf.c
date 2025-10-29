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

void	ft_type()
{
	// if % is found, select a type
	if ( == 'c')
	if ( == 's')
}

int	ft_printf(const char *str, ...)
{
	int	count;
	// va_list	args;

	if (!str)
		return (0);
	va_start(args , str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			count++;
		}

	}

	// va_arg(args, char*);
	// va_arg(args, int);
	va_end(list);
	return (count);
}
// count how many characters are printed
