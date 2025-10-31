#include "ft_printf.h"

static size_t	ft_digit_count_unsigned(long n)
{
	size_t	n_len;

	n_len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_unsigned_itoa(int n)
{
	size_t			n_len;
	unsigned int	num;
	char			*str;

	num = n;
	n_len = ft_digit_count_unsigned(num);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	str[n_len] = '\0';
	n_len--;
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[n_len] = (num % 10) + '0';
		num = num / 10;
		n_len--;
	}
	return (str);
}

int	print_unsigned(unsigned int n)
{
    
}