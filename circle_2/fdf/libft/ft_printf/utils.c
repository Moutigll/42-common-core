/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:20:15 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/22 20:42:03 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	paddr(unsigned long long addr, int mode)
{
	char	buffer[17];
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	if (addr == 0)
	{
		if (mode == 1)
			ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = 16;
	buffer[i] = '\0';
	i--;
	while (addr > 0)
	{
		buffer[i] = hex[addr % 16];
		addr = addr / 16;
		i--;
	}
	if (mode == 0)
		return (17 - i);
	ft_putstr_fd("0x", 1);
	return (ft_putstr_fd(&buffer[i + 1], 1) + 2);
}

int	phex(unsigned int nbr, int f, int mode)
{
	char	*hex;
	char	buffer[9];
	int		i;

	if (f == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nbr == 0)
	{
		if (mode == 1)
			ft_putchar_fd('0', 1);
		return (1);
	}
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	if (mode == 0)
		return (i);
	while (--i >= 0)
		ft_putchar_fd(buffer[i], 1);
	return (i + 1);
}

static int	gesize_t(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*conver_num_unsigned(unsigned int n, char *res, int size)
{
	res[size] = '\0';
	while (size > 0)
	{
		res[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (res);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*res;
	int		size;

	size = gesize_t(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	return (conver_num_unsigned(n, res, size));
}
