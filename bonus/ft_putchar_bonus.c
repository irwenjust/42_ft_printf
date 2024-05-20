/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:27:57 by likong            #+#    #+#             */
/*   Updated: 2024/05/17 16:55:26 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putchar_bonus(int c, t_flags *flags)
{
	int len;

	len = 0;
	if (flags->minus == 1)
	{
		len += put_char((char)c);
		while (len < flags->len)
			len += put_char(' ');
	}
	else if (flags->len != 0 && flags->zero == 0)
	{
		while (len < flags->len - 1)
			len += put_char(' ');
		len += put_char((char)c);
	}
	else if (flags->len != 0 && flags->zero != 0)
	{
		while (len < flags->len - 1)
			len += put_char('0');
		len += put_char((char)c);
	}
	else
		len += put_char((char)c);
	return (len);
}
