/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheung <wcheung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:24:39 by wcheung           #+#    #+#             */
/*   Updated: 2025/11/04 18:22:27 by wcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char *base)
{
	int	hex_count;

	hex_count = 0;
	if (n >= 16)
		hex_count += print_hex(n / 16, base);
	hex_count += print_char(base[n % 16]);
	return (hex_count);
}

static int	print_long_hex(unsigned long long_n, char *base)
{
	int	long_hex_count;

	long_hex_count = 0;
	if (long_n >= 16)
		long_hex_count += print_long_hex(long_n / 16, base);
	long_hex_count += print_char(base[long_n % 16]);
	return (long_hex_count);
}

int	print_pointer(void *ptr)
{
	unsigned long	temp;
	int				pointer_count;

	pointer_count = 0;
	temp = (unsigned long)ptr;
	if (!temp)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	pointer_count += 2;
	pointer_count += print_long_hex(temp, "0123456789abcdef");
	return (pointer_count);
}

// base = "0123456789abcdef";
// write(1, &base[n / 16], 1);
// write(1, &base[n % 16], 1);
