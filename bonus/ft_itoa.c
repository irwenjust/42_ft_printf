/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:54:22 by likong            #+#    #+#             */
/*   Updated: 2024/05/20 11:23:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_len(int n)
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

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	num;

	len = get_len(n);
	num = n;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	else if (num == 0)
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
