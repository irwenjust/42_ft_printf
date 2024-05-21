/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:10:48 by likong            #+#    #+#             */
/*   Updated: 2024/05/20 10:52:25 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	str_length(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_num_len(int num)
{
	int	len;

	len = 0;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = str_length(s);
	if (!s)
		return (NULL);
	while (i < len + 1)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int	get_number_size(unsigned long long num, int base_size)
{
	int					total;
	unsigned long long	nbrl;

	total = 0;
	nbrl = num;
	if (nbrl >= (unsigned long long)base_size)
	{
		total += get_number_size(nbrl / base_size, base_size);
		total += get_number_size(nbrl % base_size, base_size);
	}
	else
		total++;
	return (total);
}

int	print_number_base(unsigned long long nbr, char *base)
{
	unsigned int		base_len;
	unsigned long long	nbrl;
	int					total;

	total = 0;
	nbrl = nbr;
	base_len = str_length(base);
	if (nbrl >= base_len)
	{
		total += print_number_base(nbrl / base_len, base);
		total += print_number_base(nbrl % base_len, base);
	}
	else
	{
		total += put_char(base[nbrl]);
	}
	return (total);
}

