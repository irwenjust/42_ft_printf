/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:25:55 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 18:53:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_hash(t_flags *fg, char *str, unsigned int unum, char *buff, int *index)
{
	if (fg->hash == 2 && str == HEXL && unum > 0)
	{
		buff[(*index)++] = '0';
		buff[(*index)++] = 'x';
		fg->tlen += 2;
	}
	else if (fg->hash == 2 && str == HEXH && unum > 0)
	{
		buff[(*index)++] = '0';
		buff[(*index)++] = 'X';
		fg->tlen += 2;
	}
	return (1);
}

static int	check_zero_dot(unsigned int unum, t_flags *fg, char *str, char *buff, int *index)
{
	if (check_hash(fg, str, unum, buff, index) == -1)
		return (-1);
	if (fg->percision > fg->slen)
	{
		while (fg->slen + fg->move_len++ < fg->percision)
		{
			buff[(*index)++] = '0';
			fg->tlen++;
		}
	}
	else if (fg->zero > 0 && fg->len > fg->slen
			&& fg->percision == 0 && fg->hash == 0)
	{
		while (fg->len > fg->slen + fg->move_len++)
		{
			buff[(*index)++] = '0';
			fg->tlen++;
		}
	}
	else if (fg->zero > 0 && fg->len > fg->slen + 2
			&& fg->percision == 0)
	{
		while (fg->len > fg->slen + 2 + fg->move_len++)
		{
			buff[(*index)++] = '0';
			fg->tlen++;
		}
	}
	if (print_number_base_h(unum, str, fg, &buff, index) == -1)
		return (-1);
	return (1);
}

static int	check_front(unsigned int unum, t_flags *fg, char *str, char *buff, int *index)
{
	if (fg->hash == 2 && unum == 0)
		fg->hash = 0;
	if (fg->len > 0 && fg->dot == 1)
	{
		while (fg->len > fg->percision + fg->tlen + fg->hash
				&& fg->len > fg->slen + fg->tlen + fg->hash)
		{
			buff[(*index)++] = ' ';
			fg->tlen++;
		}
	}
	else if (fg->len > 0 && fg->dot == 0 && fg->zero == 0)
	{
		while (fg->len > fg->slen + fg->tlen + fg->hash)
		{
			buff[(*index)++] = ' ';
			fg->tlen++;
		}
	}
	if (check_zero_dot(unum, fg, str, buff, index) == -1)
		return (-1);
	return (1);
}

static int	check_minus(unsigned int unum, t_flags *fg, char *str, char *buff, int *index)
{
	if (fg->minus == 1)
	{
		if (check_hash(fg, str, unum, buff, index) == -1)
			return (-1);
		if (fg->percision > fg->slen && unum != 0)
		{
			while (fg->percision - fg->slen + fg->hash > fg->tlen)
			{
				buff[(*index)++] = '0';
				fg->tlen++;
			}
		}
		else if (fg->percision > fg->slen && unum == 0)
		{
			while (fg->percision - fg->slen > fg->tlen)
			{
				buff[(*index)++] = '0';
				fg->tlen++;
			}
		}
		if (print_number_base_h(unum, str, fg, &buff, index) == -1)
			return (-1);
		while (fg->len > fg->tlen)
		{
			buff[(*index)++] = ' ';
			fg->tlen++;
		}
	}
	else if (check_front(unum, fg, str, buff, index) == -1)
			return (-1);
	return (1);
}

int	ft_puthex_bonus(unsigned int unum, char *str, t_flags *fg)
{
	char			buff[4096];
	int				index = 0;

	if (unum == 0)
		fg->nul = 1;
	fg->slen = get_number_size((uintptr_t)unum, 16);
	if (check_minus(unum, fg, str, buff, &index) == -1)
		return (-1);
	if (write_buffer(buff, index) == -1)
		return (-1);
	return (fg->tlen);
}
