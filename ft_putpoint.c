/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:27:41 by likong            #+#    #+#             */
/*   Updated: 2024/05/08 20:14:51 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_point(unsigned long long address, int i)
{
	unsigned long long	hex_len;

	hex_len = str_length(HEXBASEL);
	if (address >= hex_len)
	{
		i = hex_point(address / hex_len, i);
		if (i == -1)
			return (-1);
		if (write(1, &HEXBASEL[address % hex_len], 1) == -1)
			return (-1);
		i++;
	}
	else
	{
		if (write(1, &HEXBASEL[address], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putpoint(void *str)
{
	int					i;
	unsigned long long	address;

	i = 0;
	address = (unsigned long long)str;
	if (write(1, "0x", 2) != 2)
		return (-1);
	i = hex_point(address, i);
	if (i == -1)
		return (-1);
	i += 2;
	return (i);
}
