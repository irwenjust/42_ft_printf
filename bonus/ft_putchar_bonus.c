/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:27:57 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 18:52:39 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_char(char c, t_flags *fg)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	fg->tlen++;
	return (1);
}

int	ft_putchar_bonus(int c, t_flags *fg)
{
	if (fg->minus == 1)
	{
		if (put_char((char)c, fg) == -1)
			return (-1);
		while (fg->tlen < fg->len)
			if (put_char(' ', fg) == -1)
				return (-1);
	}
	else if (fg->len != 0 && fg->zero == 0)
	{
		while (fg->tlen < fg->len - 1)
			if (put_char(' ', fg) == -1)
				return (-1);
		if (put_char((char)c, fg) == -1)
				return (-1);
	}
	else if (fg->len != 0 && fg->zero != 0)
	{
		while (fg->tlen < fg->len - 1)
			if (put_char('0', fg) == -1)
				return (-1);
		if (put_char((char)c, fg) == -1)
				return (-1);
	}
	else
		if (put_char((char)c, fg) == -1)
				return (-1);
	return (fg->tlen);
}
