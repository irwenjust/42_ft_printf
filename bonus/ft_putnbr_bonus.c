/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:17:23 by likong            #+#    #+#             */
/*   Updated: 2024/05/22 13:03:42 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero(t_flags *flags)
{
	//printf("flags->len: %d, total_len: %d\n", flags->len, total_len);
	while (flags->zero == 1 && flags->minus == 0 && flags->dot == 0
			&& flags->len > flags->tlen && flags->neg == 0)
	{
		if (flags->add == 1)
		{
			if (write(1, "+", 1) == -1)
				return (-1);
			flags->add = 0;
		}
		if (write(1, "0", 1) == -1)
			return (-1);
		flags->tlen++;
	}
	return (1);
}

static int	check_dot(t_flags *flags, char *str)
{
	flags->slen = str_length(str);
	if (check_zero(flags) == -1)
		return (-1);
	if (flags->add == 1)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
	}
	while (flags->percision > flags->slen++ || (flags->len > flags->tlen && flags->dot == 0 
			&& flags->minus == 0 && str))
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		flags->tlen++;
	}
	if (write(1, str, str_length(str)) == -1)
		return (-1);
	ft_free(&str);
	while (flags->minus == 1 && flags->len > flags->tlen)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		flags->tlen++;
	}
	return (1);
}

static int	check_width(t_flags *flags, char *str)
{
	if (flags->len > flags->tlen && flags->minus == 0)
	{
		while ((flags->tlen + flags->move_len < flags->len && flags->zero == 0
				&& flags->percision + flags->move_len + flags->neg + flags->add + flags->space
				< flags->len) || (flags->zero == 1 && flags->dot == 1
				&& flags->len > (flags->percision + flags->move_len + flags->neg + flags->space
				+ flags->add) && flags->len > (flags->tlen + flags->move_len)))
		{
			if(write(1, " ", 1) == -1)
				return (-1);
			flags->move_len++;
		}
		flags->tlen += flags->move_len;
	}
	if(flags->neg == 1)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		str = ft_substr(str, 1, str_length(str) - 1);
		if (!str)
			return (-1);
	}
	if (check_dot(flags, str) == -1)
		return (-1);
	return (1);
}

static int	check_add_space(t_flags *flags, char *str, int sign)
{
	if (flags->space != 0 && flags->add == 0 && sign == 1)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		flags->tlen++;
	}
	else if (flags->add != 0 && sign == 0)
		flags->add = 0;
	else if (flags->add != 0)
		flags->tlen++;
	if (sign == 0)
	{
		flags->neg = 1;
		flags->space = 0;
	}
	if (check_width(flags, str) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_bonus(int n, t_flags *flags)
{
	int		sign;
	char	*str;

	if (n < 0)
		sign = 0;
	else
		sign = 1;
	if (n == 0 && flags->percision == 0 && flags->dot == 1)
	{
		str = (char *)malloc(sizeof(char));
		*str = '\0';
	}
	else
	{
		str = ft_itoa(n);
		if (!str)
			return (0);
	}
	flags->tlen = str_length(str);
	if (check_add_space(flags, str, sign) == -1)
	{
		if (str)
			ft_free(&str);
		return (-1);
	}
	return (flags->tlen);
}
