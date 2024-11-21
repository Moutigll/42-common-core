/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:38:40 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/22 20:42:16 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_info2(t_flags *flags, t_info *info, int *i)
{
	if (info->format[*i] == '.')
	{
		flags->point = 1;
		(*i)++;
		if (ft_isdigit(info->format[*i]))
			flags->precision = ft_atoi((char *)&info->format[*i]);
		else
			flags->precision = 0;
		while (ft_isdigit(info->format[*i]))
			(*i)++;
	}
	if (info->format[*i] == '#')
	{
		flags->hash = 1;
		(*i)++;
	}
	if (info->format[*i] == ' ')
	{
		flags->space = 1;
		(*i)++;
	}
}

void	get_info1(t_flags *flags, t_info *info, int *i)
{
	while (info->format[*i] && !search_c(info->format[*i], "cspdiuxX%"))
	{
		if (info->format[*i] == '-')
		{
			flags->minus = 1;
			(*i)++;
		}
		if (info->format[*i] == '0')
		{
			flags->zero = 1;
			(*i)++;
		}
		if (ft_isdigit(info->format[*i]))
		{
			flags->field_width = ft_atoi((char *)&info->format[*i]);
			while (ft_isdigit(info->format[*i]))
				(*i)++;
		}
		if (info->format[*i] == '+')
		{
			flags->plus = 1;
			(*i)++;
		}
		get_info2(flags, info, i);
	}
}

void	right_adjusted_exceptions(t_flags flags, t_info *info, int *i, int size)
{
	va_list		args_copy;

	info->count += fspace(flags.field_width - flags.precision, ' ');
	va_copy(args_copy, info->args);
	if (va_arg(args_copy, int) < 0 && flags.zero == 1
		&& search_c(info->format[*i], "di")
		&& ((int)flags.precision != flags.field_width))
		ft_putchar_fd('-', 1);
	va_copy(args_copy, info->args);
	va_copy(args_copy, info->args);
	if (flags.field_width == (int)flags.precision
		&& flags.zero == 1 && search_c(info->format[*i], "di")
		&& va_arg(args_copy, int) < 0)
		ft_putchar_fd('0', 1);
	va_copy(args_copy, info->args);
	if (flags.field_width > (int)flags.precision
		&& flags.zero == 1 && search_c(info->format[*i], "di")
		&& va_arg(args_copy, int) < 0)
		ft_putchar_fd('0', 1);
	info->count += fspace(flags.precision - (info->count - size)
			+ (flags.field_width - flags.precision), '0');
}

void	right_adjusted(t_flags flags, t_info *info, int size, int *i)
{
	va_list		args_copy;

	if (flags.point == 1 && search_c(info->format[*i], "diuxX")
		&& info->count - size < (int)flags.precision)
	{
		va_copy(args_copy, info->args);
		if (flags.zero == 1 && flags.point == 1
			&& flags.field_width < (int)flags.precision
			&& va_arg(args_copy, int) < -9 && !search_c(info->format[*i], "xX"))
			ft_putchar_fd('0', 1);
		if (flags.field_width >= (int)flags.precision
			&& flags.minus == 0 && flags.precision > 0)
		{
			right_adjusted_exceptions(flags, info, i, size);
		}
		else
			info->count += fspace(flags.precision - (info->count - size), '0');
	}
	if (flags.minus == 0 && flags.zero == 1 && flags.point == 0
		&& search_c(info->format[*i], "diuxX")
		&& flags.field_width > info->count - size && info->format[*i] != '%')
		info->count += fspace(flags.field_width - (info->count - size), '0');
	else if (flags.minus == 0 && flags.field_width > info->count - size
		&& info->format[*i] != '%')
		info->count += fspace(flags.field_width - (info->count - size), ' ');
}

t_flags	manage_flags(t_info *info, int *i)
{
	va_list		args_copy;
	t_flags		flags;
	int			size;

	init_flags(&flags);
	get_info1(&flags, info, i);
	size = info->count;
	va_copy(args_copy, info->args);
	info->mode = 0;
	print_arg(info, *i, args_copy, flags);
	va_copy(args_copy, info->args);
	if (search_c(info->format[*i], "di") && flags.point == 1
		&& flags.precision > 1 && flags.field_width == 1 && flags.minus == 0)
	{
		if (va_arg(args_copy, int) < 0)
			info->count--;
	}
	right_adjusted(flags, info, size, i);
	info->mode = 1;
	print_arg(info, *i, args_copy, flags);
	if (flags.minus == 1 && flags.field_width > info->count - size
		&& info->format[*i] != '%')
		info->count += fspace(flags.field_width - (info->count - size), ' ');
	va_end(args_copy);
	return (flags);
}
