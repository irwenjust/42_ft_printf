/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:02:18 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 18:55:02 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero(t_flags *fg, char *buff, int *buf_index)
{
	int	offset;

	offset = 0;
	while (fg->zero == 1 && fg->minus == 0 && fg->dot == 0
			&& fg->len > fg->tlen)
	{
		buff[(*buf_index)++] = '0';
		fg->tlen++;
	}
	while (fg->zero == 1 && fg->minus == 0 && fg->dot == 1
			&& fg->len > (fg->percision + offset)
			&& fg->len > (fg->tlen + offset))
	{
		buff[(*buf_index)++] = ' ';
		offset++;
	}
	fg->tlen += offset;
	return (1);
}

static int	check_dot(t_flags *fg, unsigned int num, char *buff, int *buf_index)
{
	if (check_zero(fg, buff, buf_index) == -1)
		return (-1);
	while (fg->percision > fg->slen++)
	{
		buff[(*buf_index)++] = '0';
		fg->tlen++;
	}
	if (print_number_base_h(num, DECIMEL, fg, &buff, buf_index) == -1)
		return (-1);
	fg->tlen -= get_number_size((unsigned long long)num, 10);
	while (fg->minus == 1 && fg->len > fg->tlen)
	{
		buff[(*buf_index)++] = ' ';
		fg->tlen++;
	}
	return (1);
}

static int	check_width(t_flags *fg, unsigned int num, char *buff, int *buf_index)
{
	if (fg->len > fg->tlen && fg->minus == 0 && fg->zero == 0)
	{
		while (fg->tlen + fg->move_len < fg->len
				&& fg->percision + fg->move_len < fg->len)
		{
			buff[(*buf_index)++] = ' ';
			fg->move_len++;
		}
		fg->tlen += fg->move_len;
	}
	if (check_dot(fg, num, buff, buf_index) == -1)
		return (-1);
	return (1);
}

int	ft_putunbr_bonus(unsigned int num, t_flags *fg)
{
	char	buff[4096];
	int		buf_index = 0;
	
	if (num == 0)
		fg->nul = 1;
	if (num == 0 && fg->zero == 0 && fg->dot == 0)
		fg->nul = 0;
	fg->slen = get_number_size((unsigned long long)num, 10);
	fg->tlen = get_number_size((unsigned long long)num, 10);
	if (check_width(fg, num, buff, &buf_index) == -1)
		return (-1);
	if (write_buffer(buff, buf_index) == -1)
		return (-1);
	return (fg->tlen);
}
