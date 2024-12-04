/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:31:22 by isallali          #+#    #+#             */
/*   Updated: 2024/12/04 22:32:10 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* Flags structure */
typedef struct s_flags
{
    int space;
    int hash;
    int plus;
    int	index;
    int	ret;
} t_flags;

typedef struct s_tool
{
	int	num;
	unsigned int	n;
	unsigned int	count;
	char	buffer[12];
	int	i;
}   t_tool;

/* helpers */
char	base_to_char(unsigned long num, char c);
int	ft_puts(char c);
int	ft_putstring(char *str);

/* printers */
int		ft_putchar(va_list args, t_flags *flags);
int		ft_putstr(va_list args, t_flags *flags);
int		ft_putnbr(va_list args, t_flags *flags);
int		ft_putnbr_unsigned(va_list args, t_flags *flags);
int		ft_puthexa(va_list args, t_flags *flags);
int		ft_puthe16a(va_list args, t_flags *flags);
int		ft_putpointer(va_list args, t_flags *flags);

/* struct to hold functions */
typedef struct functions_holder
{
	char	symbol;
	int		(*puts)(va_list arg, t_flags *flags);
}	t_holder;

/* main functions */
int		ft_printf(const char *format, ...);
int		ft_looper(const char *format, t_holder *printers,
			va_list args, int *count);

#endif
