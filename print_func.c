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