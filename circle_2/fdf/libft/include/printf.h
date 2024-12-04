/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:53:40 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/06 09:56:20 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>
#include "libft.h"

typedef unsigned long long	t_addr;
typedef struct s_info
{
	const char	*format;
	int			count;
	int			mode;
	va_list		args;
}				t_info;

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		point;
	int		hash;
	int		space;
	int		plus;
	int		field_width;
	size_t	precision;
}				t_flags;

int		paddr(unsigned long long addr, int mode);
char	*ft_itoa_unsigned(unsigned int n);
int		phex(unsigned int nbr, int f, int mode);
int		ft_printf(const char *str, ...);
void	print_arg(t_info *info, int i, va_list argu, t_flags flags);
int		search_c(char c, const char *string);
char	*print_di_mode0(t_info *info, int argu, t_flags flags);
void	print_unsigned(t_info *info, int i, va_list argu, t_flags flags);
void	print_di(t_info *info, int i, va_list argu, t_flags flags);
t_flags	manage_flags(t_info *info, int *i);
int		fspace(int size, char c);
void	init_flags(t_flags *flags);
