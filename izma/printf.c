/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:26:23 by isallali          #+#    #+#             */
/*   Updated: 2024/12/05 13:19:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	t_holder	printers[9];
	int			count;
	va_list		args;

	count = 0;
	printers[0] = (f_holder){'c', ft_putchar};
	printers[1] = (f_holder){'s', ft_putstr};
	printers[2] = (f_holder){'p', ft_putpointer};
	printers[3] = (f_holder){'d', ft_putnbr};
	printers[4] = (f_holder){'i', ft_putnbr};
	printers[5] = (f_holder){'u', ft_putnbr_unsigned};
	printers[6] = (f_holder){'x', ft_puthexa};
	printers[7] = (f_holder){'X', ft_puthe16a};
	printers[8] = (f_holder){'\0', NULL};
	va_start(args, format);
	count = ft_looper(format, printers, args, &count);
	va_end(args);
	return (count);
}
