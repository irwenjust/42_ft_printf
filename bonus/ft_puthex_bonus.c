/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:25:55 by likong            #+#    #+#             */
/*   Updated: 2024/05/20 14:18:38 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_hash(t_flags *flags, char *str)
{
	int i;

	i = 0;
	if (flags->hash == 1 && str == HEXBASEL)
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		i += 2;
	}
	else if (flags->hash == 1 && str == HEXBASEH)
	{
		if (write(1, "0X", 2) != 2)
			return (-1);
		i += 2;
	}
	return (i);
}

static int	check_zero_dot(unsigned int address, t_flags *flags, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	i = check_hash(flags, str);
	if (flags->percision > flags->slen)
		while (flags->slen + j++ < flags->percision)
			i += put_char('0');
	else if (flags->zero > 0 && flags->len > flags->slen + 2
			&& flags->percision == 0)
		while (flags->len > flags->slen + 2 + j++)
			i += put_char('0');
	i += print_number_base(address, str);
	return (i);
}

static int	check_front(unsigned int address, t_flags *flags, char *str)
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
	i += check_zero_dot(address, flags, str);
	return (i);
}

static int	check_minus(unsigned int address, t_flags *flags, char *str)
{
	int	i;

	i = 0;
	if (flags->minus == 1)
	{
		i = check_hash(flags, str);
		if (flags->percision > flags->slen)
			while (flags->percision - flags->slen > i)
				i += put_char('0');
		i += print_number_base(address, str);
		while (flags->len > i)
			i += put_char(' ');
	}
	else
		i += check_front(address, flags, str);
	return (i);
}

int	ft_puthex_bonus(int num, char *str, t_flags *flags)
{
	int				i;
	unsigned int	unum;

	unum = (unsigned int)num;
	flags->slen = get_number_size((unsigned long long)unum, 16);
	i = check_minus(unum, flags, str);
	return (i);
}