
#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printchar(char c, t_opt opt)
{
	int	cur;

	cur = 0;
	while (cur + 1 < opt.min_width)
		cur += print_char(' ');
	cur += print_char(c);
	while (cur < opt.offset)
		cur += print_char(' ');
	return (cur);
}
