
#include "ft_printf.h"

int	ft_puts(char c)
{
	return (write(1, &c, 1));
}

int	ft_putchar(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_puts(c));
}

int	ft_putstring(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		if (ft_puts(str[i++]) == -1)
			return (-1);
	}
	return (i);
}

int	ft_putstr(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	return (ft_putstring(str));
}