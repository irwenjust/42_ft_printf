/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:02:11 by likong            #+#    #+#             */
/*   Updated: 2024/05/21 16:22:21 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (len > str_length(s) - start)
		len = str_length(s) - start;
	res = (char *)malloc((len + 1) * sizeof(*s));
	if (!res)
		return (NULL);
	i = 0;
	if (start <= str_length(s))
	{
		while (s[i + start] && i < len)
		{
			res[i] = s[i + start];
			i++;
		}
	}
	free(s);
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	i = 0;
	len = str_length(s1);
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)dup)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (dup);
}

int	print_number_base_h(unsigned long long nbr, char *base, t_flags *flags)
{
	unsigned int		base_len;
	unsigned long long	nbrl;
	int					total;

	if (nbr == 0 && flags->percision == 0 && flags->dot == 1 && flags->len > 0)
	{
		if(write(1, " ", 1) == -1)
			return (-1);
		return (1);
	}
	else if(nbr == 0 && flags->percision == 0 && flags->dot == 1 && flags->len == 0)
		return (0);
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
