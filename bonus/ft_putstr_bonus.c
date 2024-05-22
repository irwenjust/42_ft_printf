/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:36:52 by likong            #+#    #+#             */
/*   Updated: 2024/05/22 09:17:04 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	put_str(char *str, int *slen, t_flags *flags)
{
	int i;

	i = 0;
	while (str[i] && i < *slen)
	{
		if (write(1, &str[i], 1) != 1)
			return (-1);
		flags->tlen++;
		i++;
	}
	return (i);
}

static int	check_string(char *str, t_flags *flags, int *slen)
{
	if (flags->percision <= (int)str_length(str) && flags->dot == 1)
		*slen = flags->percision;
	else
		*slen = str_length(str);
	if (flags->minus == 1)
	{
		if (put_str(str, slen, flags) == -1)
			return (-1);
		while (flags->tlen < flags->len)
			if (put_char(' ', flags) == -1)
				return (-1);
	}
	else if (flags->len > *slen && flags->zero == 0)
	{
		while (flags->tlen < flags->len - *slen)
			if (put_char(' ', flags) == -1)
				return (-1);
		if (put_str(str, slen, flags) == -1)
			return (-1);
	}
	else if (flags->len != 0 && flags->zero != 0)
	{
		while (flags->tlen < flags->len - *slen)
			if (put_char(' ', flags) == -1)
				return (-1);
		if (put_str(str, slen, flags) == -1)
			return (-1);
	}
	else
		if (put_str(str, slen, flags) == -1)
			return (-1);
	return (flags->tlen);
}

int	ft_putstr_bonus(char *str, t_flags *flags)
{
	int	len;
	int slen;

	len = 0;
	slen = 0;
	if (!str)
	{
		str = "(null)";
		flags->slen = 6;
		flags->nul = 1;
	}
	len = check_string(str, flags, &slen);
	return (len);
}
