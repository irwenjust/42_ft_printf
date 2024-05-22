/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:27:48 by likong            #+#    #+#             */
/*   Updated: 2024/05/22 10:21:55 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero_dot(unsigned long long address, t_flags *flags)
{
	int j;

	j = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	flags->tlen += 2;
	if (flags->percision > flags->slen)
	{
		while (flags->slen + j++ < flags->percision)
		{
			if (put_char('0', flags) == -1)
				return (-1);
		}
	}
	else if (flags->zero > 0 && flags->len > flags->slen + 2
			&& flags->percision == 0)
	{
		while (flags->len > flags->slen + 2 + j++)
		{
			if (put_char('0', flags) == -1)
				return (-1);
		}
	}
	if (print_number_base(address, HEXBASEL, flags) == -1)
		return (-1);
	return (1);
}

static int	check_front(unsigned long long address, t_flags *flags)
{
	if (flags->len > 0 && flags->percision > 0)
	{
		while (flags->len > flags->percision + 2 + flags->tlen
				&& flags->len > flags->slen + 2 + flags->tlen)
			if (put_char(' ', flags) == -1)
				return (-1);
	}
	else if (flags->len > 0 && flags->percision == 0 && flags->zero == 0)
	{
		while (flags->len > flags->slen + 2 + flags->tlen)
			if (put_char(' ', flags) == -1)
				return (-1);
	}
	if (check_zero_dot(address, flags) == -1)
		return (-1);
	return (1);
}

static int	check_minus(unsigned long long address, t_flags *flags)
{
	if (flags->minus == 1)
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		if (flags->percision > flags->slen)
			while (flags->percision - flags->slen > flags->tlen)
				if (put_char('0', flags) == -1)
					return (-1);
		flags->tlen += 2;
		if (print_number_base(address, HEXBASEL, flags) == -1)
			return (-1);
		while (flags->len > flags->tlen)
			if (put_char(' ', flags) == -1)
				return (-1);
	}
	else
		if (check_front(address, flags) == -1)
			return (-1);
	return (1);
}

int	ft_putpoint_bonus(void *str, t_flags *flags)
{
	unsigned long long	address;

	address = (unsigned long long)str;
	flags->slen = get_number_size(address, 16);
	if (check_minus(address, flags) == -1)
		return (-1);
	return (flags->tlen);
}
