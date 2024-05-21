/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:02:18 by likong            #+#    #+#             */
/*   Updated: 2024/05/20 11:24:13 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero(int total_len, t_flags *flags)
{
	int	offset;

	offset = 0;
	while (flags->zero == 1 && flags->minus == 0 && flags->percision == 0
			&& flags->len > total_len)
	{
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
	while (flags->percision > slen++)
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
	if (flags->len > total_len && flags->minus == 0 && flags->zero == 0)
	{
		while (total_len + flags->move_len < flags->len
				&& flags->percision + flags->move_len < flags->len)
		{
			if(write(1, " ", 1) == -1)
				return (-1);
			flags->move_len++;
		}
		total_len += flags->move_len;
	}
	total_len = check_dot(total_len, flags, str);
	return (total_len);
}

int	ft_putunbr_bonus(unsigned int n, t_flags *flags)
{
	char			*str;
	int				total_len;
	
	str = ft_itoa_p(n);
	if (!str)
		return (0);
	total_len = str_length(str);
	total_len = check_width(total_len, flags, str);
	return (total_len);
}
