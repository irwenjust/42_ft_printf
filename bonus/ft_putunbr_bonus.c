/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:02:18 by likong            #+#    #+#             */
/*   Updated: 2024/05/22 14:20:32 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero(t_flags *flags)
{
	int	offset;

	offset = 0;
	while (flags->zero == 1 && flags->minus == 0 && flags->dot == 0
			&& flags->len > flags->tlen)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		flags->tlen++;
	}
	while (flags->zero == 1 && flags->minus == 0 && flags->dot == 1
			&& flags->len > (flags->percision + offset)
			&& flags->len > (flags->tlen + offset))
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		offset++;
	}
	flags->tlen += offset;
	return (1);
}

static int	check_dot(t_flags *flags, char *str)
{
	int slen;

	slen = str_length(str);
	if (check_zero(flags) == -1)
		return (-1);
	while (flags->percision > slen++)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		flags->tlen++;
	}
	if (write(1, str, str_length(str)) == -1)
		return (-1);
	free(str);
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
	if (flags->len > flags->tlen && flags->minus == 0 && flags->zero == 0)
	{
		while (flags->tlen + flags->move_len < flags->len
				&& flags->percision + flags->move_len < flags->len)
		{
			if(write(1, " ", 1) == -1)
				return (-1);
			flags->move_len++;
		}
		flags->tlen += flags->move_len;
	}
	if (check_dot(flags, str) == -1)
		return (-1);
	return (1);
}

int	ft_putunbr_bonus(unsigned int n, t_flags *flags)
{
	char			*str;
	
	if (n == 0 && flags->percision == 0 && flags->dot == 1)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (-1);
		*str = '\0';
	}
	else
	{
		str = ft_itoa_p(n);
		if (!str)
			return (-1);
	}
	flags->tlen = str_length(str);
	if (check_width(flags, str) == -1)
	{
		if (str)
			ft_free(&str);
		return (-1);
	}
	return (flags->tlen);
}
