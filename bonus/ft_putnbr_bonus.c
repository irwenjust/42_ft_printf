/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:17:23 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 17:26:05 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int write_buffer(char *buffer, int len)
{
	return (write(1, buffer, len));
}

static int	check_zero(t_flags *flags, char *buff, int *buf_index)
{
	//printf ("before_tlen: %d, len: %d, per: %d, slen: %d\n", flags->tlen, flags->len, flags->percision, flags->slen);
	while (flags->zero == 1 && flags->minus == 0 && flags->dot == 0
			&& flags->len > flags->tlen && flags->neg == 0)
	{
		if (flags->add == 1)
		{
			buff[(*buf_index)++] = '+';
			flags->add = 0;
		}
		buff[(*buf_index)++] = '0';
		flags->tlen++;
	}
	return (1);
}

static int	check_dot(t_flags *flags, long num, char *buff, int *buf_index)
{
	if (check_zero(flags, buff, buf_index) == -1)
		return (-1);
	if (flags->add == 1)
		buff[(*buf_index)++] = '+';
	while (flags->percision > flags->slen++ || (flags->len > flags->tlen && flags->dot == 0 
			&& flags->minus == 0 && flags->nul != 1))
	{
		buff[(*buf_index)++] = '0';
		flags->tlen++;
	}
	if (print_number_base_h(num, DECIMEL, flags, &buff, buf_index) == -1)
		return (-1);
	//printf("len: %d, tlen: %d, index: %d\n", flags->len, flags->tlen, *buf_index);
	flags->tlen -= get_number_size((unsigned long long)num, 10);
	while (flags->minus == 1 && flags->len > flags->tlen)
	{
		buff[(*buf_index)++] = ' ';
		flags->tlen++;
	}
	return (1);
}

static int	check_width(t_flags *flags, long num, char *buff, int *buf_index)
{
	//printf("nul: %d, tlen: %d, len: %d\n", flags->nul, flags->tlen, flags->len);
	if (flags->len > flags->tlen && flags->minus == 0)
	{
		while ((flags->tlen + flags->move_len + flags->neg - flags->nul < flags->len && flags->zero == 0
				&& flags->percision + flags->move_len + flags->neg + flags->add + flags->space
				< flags->len) || (flags->zero == 1 && flags->dot == 1
				&& flags->len > (flags->percision + flags->move_len + flags->neg + flags->space
				+ flags->add) && flags->len > (flags->tlen + flags->neg + flags->move_len - flags->nul)))
		{
			buff[(*buf_index)++] = ' ';
			flags->move_len++;
		}
		flags->tlen += flags->move_len;
	}
	if(flags->neg == 1)
	{
		buff[(*buf_index)++] = '-';
		flags->tlen++;
	}
	if (check_dot(flags, num, buff, buf_index) == -1)
		return (-1);
	return (1);
}

static int	check_add_space(t_flags *flags, long num, char *buff, int *buf_index)
{
	if (flags->space != 0 && flags->add == 0 && flags->neg == 0)
	{
		buff[(*buf_index)++] = ' ';
		flags->tlen++;
	}
	else if (flags->add != 0 && flags->neg == 1)
		flags->add = 0;
	else if (flags->add != 0)
		flags->tlen++;
	if (flags->neg == 1)
		flags->space = 0;
	if (check_width(flags, num, buff, buf_index) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_bonus(int n, t_flags *flags)
{
	long	num;
	char	buff[4096];
	int		buf_index = 0;

	num = n;
	if (num < 0)
	{
		flags->neg = 1;
		num = -num;
	}
	if (num == 0)
		flags->nul = 1;
	if (num == 0 && flags->zero == 0 && flags->dot == 0)
		flags->nul = 0;
	flags->slen = get_number_size((unsigned long long)num, 10);
	flags->tlen = get_number_size((unsigned long long)num, 10);
	if (check_add_space(flags, num, buff, &buf_index) == -1)
		return (-1);
	if (write_buffer(buff, buf_index) == -1)
		return (-1);
	return (flags->tlen);
}
