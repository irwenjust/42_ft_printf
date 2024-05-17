/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:27:48 by likong            #+#    #+#             */
/*   Updated: 2024/05/17 14:06:12 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero_dot(unsigned long long address, t_flags *flags)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	i += 2;
	if (flags->percision > flags->slen)
		while (flags->slen + j++ < flags->percision)
			i += put_char('0');
	else if (flags->zero > 0 && flags->len > flags->slen + 2
			&& flags->percision == 0)
		while (flags->len > flags->slen + 2 + j++)
			i += put_char('0');
	i += print_number_base(address, HEXBASEL);
	return (i);
}

static int	check_front(unsigned long long address, t_flags *flags)
{
	int i;

	i = 0;
	if (flags->len > 0 && flags->percision > 0)
		while (flags->len > flags->percision + 2 + i
				&& flags->len > flags->slen + 2 + i)
			i += put_char(' ');
	else if (flags->len > 0 && flags->percision == 0 && flags->zero == 0)
		while (flags->len > flags->slen + 2 + i)
			i += put_char(' ');
	i += check_zero_dot(address, flags);
	return (i);
}

static int	check_minus(unsigned long long address, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->minus == 1)
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		if (flags->percision > flags->slen)
			while (flags->percision - flags->slen > i)
				i += put_char('0');
		i += 2;
		i += print_number_base(address, HEXBASEL);
		while (flags->len > i)
			i += put_char(' ');
	}
	else
		i += check_front(address, flags);
	return (i);
}

int	ft_putpoint_bonus(void *str, t_flags *flags)
{
	int					i;
	unsigned long long	address;

	address = (unsigned long long)str;
	flags->slen = get_hex_size(address);
	i = check_minus(address, flags);
	/*
	if (write(1, "0x", 2) != 2)
		return (-1);
	*/
	return (i);
}
