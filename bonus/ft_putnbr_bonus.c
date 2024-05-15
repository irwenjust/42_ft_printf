/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:17:23 by likong            #+#    #+#             */
/*   Updated: 2024/05/15 11:01:06 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_dot(int total_len, t_flags *flags, char *str, int mark)
{
	int slen;

	slen = str_length(str);
	while (mark == 3 && flags->minus == 0 && flags->dot == 0
			&& flags->zero_offset > total_len++)
		if (write(1, "0", 1) == -1)
			return (-1);
	while (mark == 3 && flags->minus == 0 && flags->dot != 0
			&& flags->zero_offset > flags->percision
			&& flags->zero_offset > (flags->add + total_len++))
		if (write(1, " ", 1) == -1)
			return (-1);
	while ((mark == 1 || mark == 2) && flags->percision > slen++)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		total_len++;
	}
	if (mark == 3 && flags->add == 1)
		if (write(1, "+", 1) == -1)
			return (-1);
	if (write(1, str, str_length(str)) == -1)
		return (-1);
	while (mark == 1 && flags->minus_offset > total_len++)
		if (write(1, " ", 1) == -1)
			return (-1);
	return (total_len);
}

static int	check_minus_zero(int total_len, t_flags *flags, char *str)
{
	int mark;
	//printf("len: %d, flags->minus = %d, flags->minus_offset = %d\n", len, flags->minus, flags->minus_offset);
	mark = 0;
	if (flags->minus != 0 && flags->minus_offset >= total_len)
	{
		flags->len = flags->minus_offset;
		mark = 1;
	}
	else if (flags->len > total_len)
	{
		while (total_len++ <= (flags->len - flags->percision))
			write(1, " ", 1);
		mark = 2;
		total_len = flags->len;
	}
	else if (flags->zero != 0 && flags->zero_offset > total_len)
	{
		flags->len = flags->zero_offset;
		mark = 3;
	}
	total_len = check_dot(total_len, flags, str, mark);
	return (total_len);
}

static int	check_add_space(int total_len, t_flags *flags, char *str, int sign)
{
	if (flags->space != 0 && flags->add == 0)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		total_len++;
	}
	else if (flags->add != 0 && sign == 1 && flags->minus != 0)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
		total_len++;
	}
	total_len = check_minus_zero(total_len, flags, str);
	return (total_len);
}

int	ft_putnbr_bonus(int n, t_flags *flags)
{
	int		total_len;
	int		sign;
	char	*str;

	total_len = 0;
	if (n < 0)
		sign = 0;
	else
		sign = 1;
	str = ft_itoa(n);
	if (!str)
	{
		free(flags);
		return (0);
	}
	total_len = str_length(str);
	//printf("str: %s, len: %d\n", str, len);
	total_len = check_add_space(total_len, flags, str, sign);
	return (total_len);
}
