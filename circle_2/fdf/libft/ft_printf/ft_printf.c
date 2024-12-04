/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:30:35 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/22 20:41:50 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

int	search_c(char c, const char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	fspace(int size, char c)
{
	int	i;

	i = 0;
	while (size)
	{
		ft_putchar_fd(c, 1);
		size--;
		i++;
	}
	return (i);
}

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->point = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->field_width = 0;
	flags->precision = 1000;
}

void	manage_flags2(t_info *info, int *i, t_flags *flags)
{
	va_list		args_copy;

	if (search_c(info->format[*i], "di") && flags->point == 1
		&& (flags->precision == 0 || flags->precision == 1)
		&& flags->field_width == 1 && flags->minus == 0)
	{
		if (va_arg(args_copy, int) < 0)
			info->count--;
	}
	va_end(args_copy);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_flags	flags;
	t_info	info;

	va_start(info.args, str);
	info.format = str;
	info.count = 0;
	info.mode = 0;
	i = 0;
	while (info.format[i])
	{
		if (info.format[i] != '%')
		{
			ft_putchar_fd(info.format[i], 1);
			info.count++;
			i++;
			continue ;
		}
		i++;
		flags = manage_flags(&info, &i);
		manage_flags2(&info, &i, &flags);
		i++;
	}
	va_end(info.args);
	return (info.count);
}
