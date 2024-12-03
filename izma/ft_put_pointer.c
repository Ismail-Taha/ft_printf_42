/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:32:03 by yrachidi          #+#    #+#             */
/*   Updated: 2024/11/26 14:35:55 by yrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(va_list args)
{
	unsigned long	num;
	char			buffer[17];
	int				i;

	num = (unsigned long)va_arg(args, void *);
	buffer[16] = '\0';
	i = 15;
	if (num == 0)
		return (ft_putstring("(nil)"));
	while (num > 0)
	{
		buffer[i--] = base_to_char(num % 16, 'x');
		num /= 16;
	}
	return (ft_putstring("0x") + ft_putstring(buffer + i + 1));
}
