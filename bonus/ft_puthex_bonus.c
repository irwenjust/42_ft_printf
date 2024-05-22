/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:25:55 by likong            #+#    #+#             */
/*   Updated: 2024/05/22 11:00:13 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_hash(t_flags *flags, char *str, unsigned int unum)
{
	if (flags->hash == 2 && str == HEXBASEL && unum > 0)
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		flags->tlen += 2;
	}
	else if (flags->hash == 2 && str == HEXBASEH && unum > 0)
	{
		if (write(1, "0X", 2) != 2)
			return (-1);
		flags->tlen += 2;
	}
	return (1);
}

static int	check_zero_dot(unsigned int unum, t_flags *flags, char *str)
{
	if (check_hash(flags, str, unum) == -1)
		return (-1);
	if (flags->percision > flags->slen)
	{
		while (flags->slen + flags->move_len++ < flags->percision)
			if (put_char('0', flags) == -1)
				return (-1);
	}
	else if (flags->zero > 0 && flags->len > flags->slen
			&& flags->percision == 0 && flags->hash == 0)
	{
		while (flags->len > flags->slen + flags->move_len++)
			if (put_char('0', flags) == -1)
				return (-1);
	}
	else if (flags->zero > 0 && flags->len > flags->slen + 2
			&& flags->percision == 0)
	{
		while (flags->len > flags->slen + 2 + flags->move_len++)
			if (put_char('0', flags) == -1)
				return (-1);
	}
	if (print_number_base_h(unum, str, flags) == -1)
		return (-1);
	return (1);
}

static int	check_front(unsigned int unum, t_flags *flags, char *str)
{
	if (flags->hash == 2 && unum == 0)
		flags->hash = 0;
	if (flags->len > 0 && flags->dot == 1)
	{
		while (flags->len > flags->percision + flags->tlen + flags->hash
				&& flags->len > flags->slen + flags->tlen + flags->hash)
			if (put_char(' ', flags) == -1)
				return (-1);
	}
	else if (flags->len > 0 && flags->dot == 0 && flags->zero == 0)
	{
		while (flags->len > flags->slen + flags->tlen + flags->hash)
			if (put_char(' ', flags) == -1)
				return (-1);
	}
	if (check_zero_dot(unum, flags, str) == -1)
		return (-1);
	return (1);
}

static int	check_minus(unsigned int unum, t_flags *flags, char *str)
{
	if (flags->minus == 1)
	{
		if (check_hash(flags, str, unum) == -1)
			return (-1);
		if (flags->percision > flags->slen && unum != 0)
		{
			while (flags->percision - flags->slen + flags->hash > flags->tlen)
				if (put_char('0', flags) == -1)
					return (-1);
		}
		else if (flags->percision > flags->slen && unum == 0)
		{
			while (flags->percision - flags->slen > flags->tlen)
				if (put_char('0', flags) == -1)
					return (-1);
		}
		if (print_number_base_h(unum, str, flags) == -1)
			return (-1);
		while (flags->len > flags->tlen)
			if (put_char(' ', flags) == -1)
			return (-1);
	}
	else if (check_front(unum, flags, str) == -1)
			return (-1);
	return (1);
}

int	ft_puthex_bonus(int num, char *str, t_flags *flags)
{
	unsigned int	unum;

	unum = (unsigned int)num;
	flags->slen = get_number_size((unsigned long long)unum, 16);
	if (check_minus(unum, flags, str) == -1)
		return (-1);
	return (flags->tlen);
}
