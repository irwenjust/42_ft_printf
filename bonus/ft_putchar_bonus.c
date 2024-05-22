/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:27:57 by likong            #+#    #+#             */
/*   Updated: 2024/05/22 09:09:06 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_char(char c, t_flags *flags)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	flags->tlen++;
	return (1);
}

int	ft_putchar_bonus(int c, t_flags *flags)
{
	if (flags->minus == 1)
	{
		if (put_char((char)c, flags) == -1)
			return (-1);
		while (flags->tlen < flags->len)
			if (put_char(' ', flags) == -1)
				return (-1);
	}
	else if (flags->len != 0 && flags->zero == 0)
	{
		while (flags->tlen < flags->len - 1)
			if (put_char(' ', flags) == -1)
				return (-1);
		if (put_char((char)c, flags) == -1)
				return (-1);
	}
	else if (flags->len != 0 && flags->zero != 0)
	{
		while (flags->tlen < flags->len - 1)
			if (put_char('0', flags) == -1)
				return (-1);
		if (put_char((char)c, flags) == -1)
				return (-1);
	}
	else
		if (put_char((char)c, flags) == -1)
				return (-1);
	return (flags->tlen);
}
