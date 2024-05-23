/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:02:11 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 18:52:13 by likong           ###   ########.fr       */
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

int	print_number_base_h(uintptr_t nbr, char *base, t_flags *fg, char **buff, int *index)
{
	unsigned int		base_len;
	uintptr_t	nbrl;
	int					total;

	if (fg->nul == 1 && fg->percision == 0 && fg->dot == 1 && fg->len > 0)
	{
		if (*index < fg->len)
		{
			(*buff)[(*index)++] = ' ';
			fg->tlen++;
		}
		return (1);
	}
	else if(fg->nul == 1 && fg->percision == 0 && fg->dot == 1 && fg->len == 0)
		return (0);
	total = 0;
	nbrl = nbr;
	base_len = str_length(base);
	if (nbrl >= base_len)
	{
		print_number_base_h(nbrl / base_len, base, fg, buff, index);
		print_number_base_h(nbrl % base_len, base, fg, buff, index);
	}
	else
	{
		(*buff)[(*index)++] = base[nbrl];
		fg->tlen++;
	}
	return (1);
}
