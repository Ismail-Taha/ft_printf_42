/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:26:23 by isallali          #+#    #+#             */
/*   Updated: 2024/12/04 23:07:30 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	t_holder	printers[9];
	int			count;
	va_list		args;

	count = 0;
	printers[0] = (t_holder){'c', ft_putchar};
	printers[1] = (t_holder){'s', ft_putstr};
	printers[2] = (t_holder){'p', ft_putpointer};
	printers[3] = (t_holder){'d', ft_putnbr};
	printers[4] = (t_holder){'i', ft_putnbr};
	printers[5] = (t_holder){'u', ft_putnbr_unsigned};
	printers[6] = (t_holder){'x', ft_puthexa};
	printers[7] = (t_holder){'X', ft_puthe16a};
	printers[8] = (t_holder){'\0', NULL};
	va_start(args, format);
	count = ft_looper(format, printers, args, &count);
	va_end(args);
	return (count);
}
