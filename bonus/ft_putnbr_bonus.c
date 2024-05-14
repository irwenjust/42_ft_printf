/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:17:23 by likong            #+#    #+#             */
/*   Updated: 2024/05/14 16:43:12 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_dot(int len, t_flags *flags, char *str, int mark)
{
	while (mark == 1 && flags->percision > len)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		len++;
	}
	printf("\nstr: %s\n", str);
	return (len);
}

static int	check_minus_zero(int len, t_flags *flags, char *str)
{
	int mark;
	//printf("len: %d, flags->minus = %d, flags->minus_offset = %d\n", len, flags->minus, flags->minus_offset);
	mark = 0;
	if (flags->minus != 0 && flags->minus_offset >= len)
	{
		flags->len = flags->minus_offset;
		mark = 1;
	}
	else if (flags->len > len)
	{}
	else if (flags->zero != 0 && flags->zero_offset > len)
	{}
	len = check_dot(len, flags, str, mark);
	return (len);
}

static int	check_add_space(int len, t_flags *flags, char *str, int sign)
{
	if (flags->space != 0 && flags->add == 0)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
	}
	else if (flags->add != 0 && sign == 1)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
	}
	len = check_minus_zero(len, flags, str);
	len++;
	return (len);
}

int	ft_putnbr_bonus(int n, t_flags *flags)
{
	int		len;
	int		sign;
	char	*str;

	len = 0;
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
	len = str_length(str);
	//printf("str: %s, len: %d\n", str, len);
	len = check_add_space(len, flags, str, sign);
	return (len);
}
