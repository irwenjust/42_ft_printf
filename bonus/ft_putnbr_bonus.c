/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:17:23 by likong            #+#    #+#             */
/*   Updated: 2024/05/21 10:55:07 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero(int total_len, t_flags *flags)
{
	int	offset;

	offset = 0;
	while (flags->zero == 1 && flags->minus == 0 && flags->percision == 0
			&& flags->len > total_len && flags->neg == 0)
	{
		if (flags->add == 1)
		{
			if (write(1, "+", 1) == -1)
				return (-1);
			flags->add = 0;
		}
		if (write(1, "0", 1) == -1)
			return (-1);
		total_len++;
	}
	while (flags->zero == 1 && flags->minus == 0 && flags->percision != 0
			&& flags->len > (flags->percision + offset)
			&& flags->len > (total_len + offset))
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		offset++;
	}
	total_len += offset;
	return (total_len);
}

static int	check_dot(int total_len, t_flags *flags, char *str)
{
	int slen;

	slen = str_length(str);
	total_len = check_zero(total_len, flags);
	if (flags->add == 1)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
	}
	while (flags->percision > slen++ || (flags->len > total_len && flags->percision == 0 && flags->minus == 0))
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		total_len++;
	}
	if (write(1, str, str_length(str)) == -1)
		return (-1);
	free(str);
	while (flags->minus == 1 && flags->len > total_len)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		total_len++;
	}
	return (total_len);
}

static int	check_width(int total_len, t_flags *flags, char *str)
{
	if (flags->len > total_len && flags->minus == 0)
	{
		while (total_len + flags->move_len < flags->len && flags->zero == 0
				&& flags->percision + flags->move_len + flags->neg + flags->add < flags->len)
		{
			if(write(1, " ", 1) == -1)
				return (-1);
			flags->move_len++;
		}
		total_len += flags->move_len;
	}
	if(flags->neg == 1)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		str = ft_substr(str, 1, str_length(str) - 1);
		if (!str)
			return (0);
	}
	total_len = check_dot(total_len, flags, str);
	return (total_len);
}

static int	check_add_space(int total_len, t_flags *flags, char *str, int sign)
{
	if ((flags->space != 0 && flags->add == 0 && sign == 1
		&& flags->percision >= flags->len) || (flags->space != 0 
		&& flags->add == 0 && sign == 1 && flags->percision == 0))
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		total_len++;
	}
	else if (flags->add != 0 && sign == 0)
		flags->add = 0;
	else if (flags->add != 0)
		total_len++;
	if (sign == 0)
		flags->neg = 1;
	total_len = check_width(total_len, flags, str);
	return (total_len);
}

int	ft_putnbr_bonus(int n, t_flags *flags)
{
	int		total_len;
	int		sign;
	char	*str;

	if (n < 0)
		sign = 0;
	else
		sign = 1;
	str = ft_itoa(n);
	if (!str)
		return (0);
	total_len = str_length(str);
	//printf("str: %s, len: %d\n", str, total_len);
	total_len = check_add_space(total_len, flags, str, sign);
	return (total_len);
}
