/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:20:12 by isallali          #+#    #+#             */
/*   Updated: 2024/12/04 23:06:44 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	check_format(const char *format)
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

static int	print_specf(char c, t_holder *printers,
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
	return (ft_puts('%') + ft_puts(c));
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

int	process(const char *format, t_holder *printers,
		va_list args, int *count)
{
	t_flags	flags;

	if (ft_format_checker(format))
		return (-1);
	flags.index = 0;
	while (format[flags.index])
	{
		if (format[flags.index] == '%')
		{
			pars_flag(format, &flags, &flags.index);
			if (format[flags.index] == '%')
			{
				*count += ft_puts(format[flags.index++]);
				continue ;
			}
			flags.ret = print_specifier(format[flags.index++],
					printers, args, &flags);
			if (flags.ret == -1)
				return (-1);
			*count += flags.ret;
		}
		else
			*count += ft_puts(format[flags.index++]);
	}
	return (*count);
}
