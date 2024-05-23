/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:36:52 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 18:54:42 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	put_str(char *str, int *slen, t_flags *fg)
{
	int i;

	i = 0;
	while (str[i] && i < *slen)
	{
		if (write(1, &str[i], 1) != 1)
			return (-1);
		fg->tlen++;
		i++;
	}
	return (i);
}

static int	check_string(char *str, t_flags *fg, int *slen)
{
	if (fg->percision <= (int)str_length(str) && fg->dot == 1)
		*slen = fg->percision;
	else
		*slen = str_length(str);
	if (fg->minus == 1)
	{
		if (put_str(str, slen, fg) == -1)
			return (-1);
		while (fg->tlen < fg->len)
			if (put_char(' ', fg) == -1)
				return (-1);
	}
	else if (fg->len > *slen && fg->zero == 0)
	{
		while (fg->tlen < fg->len - *slen)
			if (put_char(' ', fg) == -1)
				return (-1);
		if (put_str(str, slen, fg) == -1)
			return (-1);
	}
	else if (fg->len != 0 && fg->zero != 0)
	{
		while (fg->tlen < fg->len - *slen)
			if (put_char(' ', fg) == -1)
				return (-1);
		if (put_str(str, slen, fg) == -1)
			return (-1);
	}
	else
		if (put_str(str, slen, fg) == -1)
			return (-1);
	return (fg->tlen);
}

int	ft_putstr_bonus(char *str, t_flags *fg)
{
	int	len;
	int slen;

	len = 0;
	slen = 0;
	if (!str)
	{
		str = "(null)";
		fg->slen = 6;
		fg->nul = 1;
	}
	len = check_string(str, fg, &slen);
	return (len);
}
