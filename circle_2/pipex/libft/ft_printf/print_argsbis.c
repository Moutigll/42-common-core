/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argsbis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:30:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/22 20:42:08 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*print_di_mode0(t_info *info, int tmp, t_flags flags)
{
	char	*str_tmp;

	if (tmp < 0 && flags.point == 1 && flags.zero == 0)
	{
		ft_putchar_fd('-', 1);
		info->count--;
	}
	if (tmp < 0 && flags.zero == 1 && flags.field_width
		<= (int)flags.precision + 1)
		ft_putchar_fd('-', 1);
	if (flags.plus == 1 && tmp >= 0)
	{
		ft_putchar_fd('+', 1);
		info->count++;
	}
	else if (flags.space == 1 && tmp >= 0)
	{
		ft_putchar_fd(' ', 1);
		info->count++;
	}
	str_tmp = ft_itoa(tmp);
	if (!(tmp == 0 && flags.point == 1))
		info->count += ft_strlen(str_tmp);
	return (str_tmp);
}

char	*print_di_mode1(t_info *info, t_flags flags)
{
	int		tmp;
	char	*str_tmp;

	tmp = va_arg(info->args, int);
	if (tmp < 0 && tmp != -2147483648 && flags.point == 1)
	{
		tmp *= -1;
		info->count++;
	}
	if (tmp < 0 && tmp != -2147483648 && flags.zero == 1)
		tmp *= -1;
	str_tmp = ft_itoa(tmp);
	if (tmp == -2147483648 && flags.point == 1)
	{
		ft_putstr_fd("2147483648", 1);
		info->count++;
	}
	else if (tmp == -2147483648 && flags.zero == 1)
		ft_putstr_fd("2147483648", 1);
	else if (!(tmp == 0 && flags.point == 1))
		ft_putstr_fd(str_tmp, 1);
	return (str_tmp);
}

void	print_di(t_info *info, int i, va_list argu, t_flags flags)
{
	char	*str_tmp;

	if (search_c(info->format[i], "di"))
	{
		if (info->mode == 0)
		{
			str_tmp = print_di_mode0(info, va_arg(argu, int), flags);
		}
		else
		{
			str_tmp = print_di_mode1(info, flags);
		}
		free(str_tmp);
	}
}

void	print_unsigned(t_info *info, int i, va_list argu, t_flags flags)
{
	int		tmp;
	char	*str_tmp;

	if (info->format[i] == 'u')
	{
		if (info->mode == 0)
		{
			tmp = va_arg(argu, unsigned int);
			str_tmp = ft_itoa_unsigned(tmp);
			if (!(tmp == 0 && flags.point == 1))
				info->count += ft_strlen(str_tmp);
		}
		else
		{
			tmp = va_arg(info->args, unsigned int);
			str_tmp = ft_itoa_unsigned(tmp);
			if (!(tmp == 0 && flags.point == 1))
				ft_putstr_fd(str_tmp, 1);
		}
		free(str_tmp);
	}
}
