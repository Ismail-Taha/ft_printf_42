#include "ft_printf.h"

int	ft_putpointer(va_list args, t_flags *flags)
{
	unsigned long	num;
	char			buffer[17];
	int				i;
	int count = 0;

	num = (unsigned long)va_arg(args, void *);
	buffer[16] = '\0';
	i = 15;
	
	if (num == 0)
		return (ft_putstring("(nil)"));
	if (flags->space)
		count += ft_puts(' ');
	while (num > 0)
	{
		buffer[i--] = base_to_char(num % 16, 'x');
		num /= 16;
	}
	count += ft_putstring("0x") + ft_putstring(buffer + i + 1);
	return (count);
}
