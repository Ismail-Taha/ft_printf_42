#include "ft_printf.h"

static int	ft_format_checker(const char *format)
{
	int	i;

	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (1);
			i += 2;
		}
		else
			i++;
	}
	return (0);
}

static int	print_specifier(char c, t_holder *printers, va_list args, t_flags *flags)
{
	int	j;

	j = 0;
	while (printers[j].symbol)
	{
		if (printers[j].symbol == c)
			return (printers[j].puts(args, flags));
		j++;
	}
	return (ft_puts('%') + ft_puts(c));
}

int	ft_looper(const char *format, t_holder *printers,
		va_list args, int *count)
{
	int	i;
	int	ret;
	t_flags flags;

	if (ft_format_checker(format))
		return (-1);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			// Reset flags
			flags.space = 0;
			flags.hash = 0;
			flags.plus = 0;

			// Parse flags if any
			while (format[i] == ' ' || format[i] == '#' || format[i] == '+')
			{
				if (format[i] == ' ')
					flags.space = 1;
				else if (format[i] == '#')
					flags.hash = 1;
				else if (format[i] == '+')
					flags.plus = 1;
				i++;
			}

			if (format[i] == '%')
			{
				*count += ft_puts(format[i++]);
				continue ;
			}
			ret = print_specifier(format[i++], printers, args, &flags);
			if (ret == -1)
				return (-1);
			*count += ret;
		}
		else
			*count += ft_puts(format[i++]);
	}
	return (*count);
}