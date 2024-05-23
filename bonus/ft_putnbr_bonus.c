/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:17:23 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 18:54:25 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int write_buffer(char *buffer, int len)
{
	return (write(1, buffer, len));
}

static int	check_zero(t_flags *fg, char *buff, int *buf_index)
{
	//printf ("before_tlen: %d, len: %d, per: %d, slen: %d\n", fg->tlen, fg->len, fg->percision, fg->slen);
	while (fg->zero == 1 && fg->minus == 0 && fg->dot == 0
			&& fg->len > fg->tlen && fg->neg == 0)
	{
		if (fg->add == 1)
		{
			buff[(*buf_index)++] = '+';
			fg->add = 0;
		}
		buff[(*buf_index)++] = '0';
		fg->tlen++;
	}
	return (1);
}

static int	check_dot(t_flags *fg, long num, char *buff, int *buf_index)
{
	if (check_zero(fg, buff, buf_index) == -1)
		return (-1);
	if (fg->add == 1)
		buff[(*buf_index)++] = '+';
	while (fg->percision > fg->slen++ || (fg->len > fg->tlen && fg->dot == 0 
			&& fg->minus == 0 && fg->nul != 1))
	{
		buff[(*buf_index)++] = '0';
		fg->tlen++;
	}
	if (print_number_base_h(num, DECIMEL, fg, &buff, buf_index) == -1)
		return (-1);
	//printf("len: %d, tlen: %d, index: %d\n", fg->len, fg->tlen, *buf_index);
	fg->tlen -= get_number_size((unsigned long long)num, 10);
	while (fg->minus == 1 && fg->len > fg->tlen)
	{
		buff[(*buf_index)++] = ' ';
		fg->tlen++;
	}
	return (1);
}

static int	check_width(t_flags *fg, long num, char *buff, int *buf_index)
{
	//printf("nul: %d, tlen: %d, len: %d\n", fg->nul, fg->tlen, fg->len);
	if (fg->len > fg->tlen && fg->minus == 0)
	{
		while ((fg->tlen + fg->move_len + fg->neg - fg->nul < fg->len && fg->zero == 0
				&& fg->percision + fg->move_len + fg->neg + fg->add + fg->space
				< fg->len) || (fg->zero == 1 && fg->dot == 1
				&& fg->len > (fg->percision + fg->move_len + fg->neg + fg->space
				+ fg->add) && fg->len > (fg->tlen + fg->neg + fg->move_len - fg->nul)))
		{
			buff[(*buf_index)++] = ' ';
			fg->move_len++;
		}
		fg->tlen += fg->move_len;
	}
	if(fg->neg == 1)
	{
		buff[(*buf_index)++] = '-';
		fg->tlen++;
	}
	if (check_dot(fg, num, buff, buf_index) == -1)
		return (-1);
	return (1);
}

static int	check_add_space(t_flags *fg, long num, char *buff, int *buf_index)
{
	if (fg->space != 0 && fg->add == 0 && fg->neg == 0)
	{
		buff[(*buf_index)++] = ' ';
		fg->tlen++;
	}
	else if (fg->add != 0 && fg->neg == 1)
		fg->add = 0;
	else if (fg->add != 0)
		fg->tlen++;
	if (fg->neg == 1)
		fg->space = 0;
	if (check_width(fg, num, buff, buf_index) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_bonus(int n, t_flags *fg)
{
	long	num;
	char	buff[4096];
	int		buf_index = 0;

	num = n;
	if (num < 0)
	{
		fg->neg = 1;
		num = -num;
	}
	if (num == 0)
		fg->nul = 1;
	if (num == 0 && fg->zero == 0 && fg->dot == 0)
		fg->nul = 0;
	fg->slen = get_number_size((unsigned long long)num, 10);
	fg->tlen = get_number_size((unsigned long long)num, 10);
	if (check_add_space(fg, num, buff, &buf_index) == -1)
		return (-1);
	if (write_buffer(buff, buf_index) == -1)
		return (-1);
	return (fg->tlen);
}
