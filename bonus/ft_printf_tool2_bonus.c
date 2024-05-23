/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:02:11 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 16:26:25 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
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

int	print_number_base_h(unsigned long long nbr, char *base, t_flags *flags, char **buff, int *index)
{
	unsigned int		base_len;
	unsigned long long	nbrl;
	int					total;

	if (flags->nul == 1 && flags->percision == 0 && flags->dot == 1 && flags->len > 0)
	{
		if (*index < flags->len)
		{
			(*buff)[(*index)++] = ' ';
			flags->tlen++;
		}
		return (1);
	}
	else if(flags->nul == 1 && flags->percision == 0 && flags->dot == 1 && flags->len == 0)
		return (0);
	total = 0;
	nbrl = nbr;
	base_len = str_length(base);
	if (nbrl >= base_len)
	{
		print_number_base_h(nbrl / base_len, base, flags, buff, index);
		print_number_base_h(nbrl % base_len, base, flags, buff, index);
	}
	else
	{
		(*buff)[(*index)++] = base[nbrl];
		flags->tlen++;
	}
	return (1);
}
