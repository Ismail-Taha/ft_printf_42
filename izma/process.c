/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:20:12 by isallali          #+#    #+#             */
/*   Updated: 2024/12/05 22:02:50 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_strchr(char *s, int i)
{
	char	c;

	c = (char)i;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

static int	check_format(const char *format)
{
	int	i;
	int j;
	int per;

	j = 0;
	i = 0;
	per = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_strchr("cspxXudi%", format[i]) && format[i + 1] != '\0')
			{
				i++;
				continue;
			}
			else 
				per = 1;
		}
		else
			i++;
	}
	return (per);
}

static int	print_specf(char c, t_format *printers,
	va_list args, t_flags *flags)
{
	int	j;

	j = 0;
	while (printers[j].symbol)
	{
		if (printers[j].symbol == c)
			return (printers[j].puts(args, flags));
		j++;
	}
	return (ft_putc('%') + ft_putc(c));
}

static void	pars_flag(const char *format, t_flags *flags, int *i)
{
	(*i)++;
	flags->space = 0;
	flags->hash = 0;
	flags->plus = 0;
	while (format[*(i)] == ' ' || format[*(i)] == '#' || format[*(i)] == '+')
	{
		if (format[*(i)] == ' ')
			flags->space = 1;
		else if (format[*(i)] == '#')
			flags->hash = 1;
		else if (format[*(i)] == '+')
			flags->plus = 1;
		(*i)++;
	}
}

int	process(const char *format, t_format *printers,
		va_list args, int *count)
{
	t_flags	flags;
	
	flags.index = 0;
	while (format[flags.index])
	{
		if (format[flags.index] == '%')
		{
			pars_flag(format, &flags, &flags.index);
			if (format[flags.index] == '\0' && check_format(format) == 1)
			{
				*count += ft_putc('%');
				return (*count);
			}
			else if (format[flags.index] == '\0' && check_format(format) == 0)
				return (-1);
			if (format[flags.index] == '%')
			{
				*count += ft_putc(format[flags.index++]);
				continue ;
			}
			flags.ret = print_specf(format[flags.index++],
					printers, args, &flags);
			if (flags.ret == -1)
				return (-1);
			*count += flags.ret;
		}
		else
			*count += ft_putc(format[flags.index++]);
	}
	return (*count);
}
