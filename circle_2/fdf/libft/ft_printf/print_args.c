/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:38:36 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/22 20:42:11 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_maj_x(t_info *info, int i, va_list argu, t_flags flags)
{
	int	tmp;

	if (info->format[i] == 'X')
	{
		if (info->mode == 0)
		{
			tmp = va_arg(argu, unsigned int);
			if (!(tmp == 0 && flags.point == 1))
				info->count += phex(tmp, 1, 0);
		}
		else
		{
			tmp = va_arg(info->args, unsigned int);
			if (!(tmp == 0 && flags.point == 1))
			{
				if (flags.hash == 1 && tmp != 0)
				{
					write(1, "0X", 2);
					info->count += 2;
				}
				phex(tmp, 1, 1);
			}
		}
	}
}

void	print_min_x(t_info *info, int i, va_list argu, t_flags flags)
{
	int		tmp;

	if (info->format[i] == 'x')
	{
		if (info->mode == 0)
		{
			tmp = va_arg(argu, unsigned int);
			if (!(tmp == 0 && flags.point == 1))
				info->count += phex(tmp, 0, 0);
		}
		else
		{
			tmp = va_arg(info->args, unsigned int);
			if (!(tmp == 0 && flags.point == 1))
			{
				if (flags.hash == 1 && tmp != 0)
				{
					write(1, "0x", 2);
					info->count += 2;
				}
				phex(tmp, 0, 1);
			}
		}
	}
}

void	print_string(t_info *info, int i, va_list argu, t_flags flags)
{
	char	*strr;

	if (info->format[i] == 's')
	{
		if (info->mode == 0)
			strr = va_arg(argu, char *);
		else
			strr = va_arg(info->args, char *);
		if (!(strr == NULL && flags.point == 1 && flags.precision < 6))
		{
			if (strr == NULL)
				strr = "(null)";
			if (info->mode == 0 && flags.precision > ft_strlen(strr))
				info->count += ft_strlen(strr);
			else if (info->mode == 0)
				info->count += flags.precision;
			else if (flags.precision > ft_strlen(strr))
				write(1, strr, ft_strlen(strr));
			else
				write(1, strr, flags.precision);
		}
	}
}

void	print_c(t_info *info, int i, va_list argu, t_flags flags)
{
	print_di(info, i, argu, flags);
	print_unsigned(info, i, argu, flags);
	print_min_x(info, i, argu, flags);
	print_maj_x(info, i, argu, flags);
	print_string(info, i, argu, flags);
	if (info->format[i] == 'c' && flags.precision > 0)
	{
		if (info->mode == 0)
			info->count++;
		else
			ft_putchar_fd(va_arg(info->args, int), 1);
	}
}

void	print_arg(t_info *info, int i, va_list argu, t_flags flags)
{
	print_c(info, i, argu, flags);
	if (info->format[i] == '%')
	{
		if (info->mode == 0)
			info->count++;
		else
			ft_putchar_fd('%', 1);
	}
	else if (info->format[i] == 'p')
	{
		if (info->mode == 0)
			info->count += paddr((t_addr)va_arg(argu, void *), info->mode);
		else
			paddr((t_addr)va_arg(info->args, void *), info->mode);
	}
}
