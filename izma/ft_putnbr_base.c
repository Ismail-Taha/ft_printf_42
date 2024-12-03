
#include "ft_printf.h"

char	base_to_char(unsigned long num, char c)
{
	char	*hex_digits;

	hex_digits = NULL;
	if (c == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	return (hex_digits[num]);
}

int	ft_puthe16a(va_list args)
{
	char			buffer[9];
	int				i;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	buffer[8] = '\0';
	i = 7;
	if (num == 0)
		return (ft_puts('0'));
	while (num > 0)
	{
		buffer[i--] = base_to_char(num % 16, 'X');
		num /= 16;
	}
	return (ft_putstring(buffer + (i + 1)));
}

int	ft_puthexa(va_list args)
{
	char			buffer[9];
	int				i;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (ft_puts('0'));
	buffer[8] = '\0';
	i = 7;
	while (num > 0)
	{
		buffer[i--] = base_to_char(num % 16, 'x');
		num /= 16;
	}
	return (ft_putstring(buffer + i + 1));
}

int	ft_putnbr(va_list args)
{
	int				num;
	unsigned int	n;
	unsigned int	count;
	char			buffer[12];
	int				i;

	count = 0;
	i = 10;
	num = va_arg(args, int);
	if (num < 0)
	{
		count += ft_puts('-');
		n = -num;
	}
	else
		n = num;
	buffer[11] = '\0';
	if (num == 0)
		return (ft_puts('0'));
	while (n > 0)
	{
		buffer[i--] = n % 10 + '0';
		n /= 10;
	}
	return (count + ft_putstring(buffer + (i + 1)));
}

int	ft_putnbr_unsigned(va_list args)
{
	char			buffer[11];
	int				i;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (ft_puts('0'));
	i = 10;
	buffer[i] = '\0';
	while (num > 0)
	{
		buffer[--i] = num % 10 + '0';
		num /= 10;
	}
	return (ft_putstring(buffer + i));
}
