/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:45:13 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/16 16:31:07 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n, int sign)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (sign == -1)
		size = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*conver_num(int n, char *res, int size, int sign)
{
	res[size] = '\0';
	while (size > 0)
	{
		res[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		sign;

	if (n == -2147483648)
	{
		res = (char *)malloc(sizeof(char) * 12);
		if (!res)
			return (0);
		ft_strlcpy(res, "-2147483648", 12);
		return (res);
	}
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	size = get_size(n, sign);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	return (conver_num(n, res, size, sign));
}
