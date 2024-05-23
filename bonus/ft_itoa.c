/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:54:22 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 11:33:11 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_len(long num)
{
	int		size;

	size = 1;
	if (num < 0)
	{
		size++;
		num = -num;
	}
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(long n)
{
	char	*res;
	int		len;

	len = get_len(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	else if (n == 0)
	{
		res[0] = '0';
	}
	res[len--] = '\0';
	while (n > 0)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

static int	get_len_p(unsigned int n)
{
	int		size;
	long	num;

	size = 1;
	num = n;
	if (n < 0)
	{
		size++;
		num = -num;
	}
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_p(unsigned int num)
{
	char	*res;
	int		len;

	len = get_len_p(num);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	if (num == 0)
	{
		res[0] = '0';
	}
	res[len--] = '\0';
	while (num > 0)
	{
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
