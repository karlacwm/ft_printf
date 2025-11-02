/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheung <wcheung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:24:39 by wcheung           #+#    #+#             */
/*   Updated: 2025/11/02 21:38:18 by wcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// base = "0123456789abcdef";
// write(1, &base[n / 16], 1);
// write(1, &base[n % 16], 1);

#include "ft_printf.h"

int	print_hex(unsigned int n, char *base)
{
	int	hex_count;

	hex_count = 0;
	if (n >= 16)
		hex_count = hex_count + print_hex(n / 16, base);
	hex_count = hex_count + print_char(n % 16, base);
	return (hex_count);
}

int	print_pointer()
{

}
