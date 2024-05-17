/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:36:52 by likong            #+#    #+#             */
/*   Updated: 2024/05/17 13:23:33 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	put_str(char *str, int *slen)
{
	int i;

	i = 0;
	while (str[i] && i < *slen)
	{
		if (write(1, &str[i], 1) != 1)
			return (-1);
		i++;
	}
	return (i);
}

static int	check_string(char *str, t_flags *flags, int len, int *slen)
{
	if (flags->percision < (int)str_length(str) && flags-> percision > 0)
		*slen = flags->percision;
	else
		*slen = str_length(str);
	if (flags->minus == 1)
	{
		len += put_str(str, slen);
		while (len < flags->len)
			len += put_char(' ');
	}
	else if (flags->len != 0 && flags->zero == 0)
	{
		while (len < flags->len - *slen)
			len += put_char(' ');
		len += put_str(str, slen);
	}
	else if (flags->len != 0 && flags->zero != 0)
	{
		while (len < flags->len - *slen)
			len += put_char('0');
		len += put_str(str, slen);
	}
	else
		len += put_str(str, slen);
	return (len);
}

int	ft_putstr_bonus(char *str, t_flags *flags)
{
	int	len;
	int slen;

	len = 0;
	slen = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	len = check_string(str, flags, len, &slen);
	free(flags);
	return (len);
}
