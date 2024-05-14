/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:31:36 by likong            #+#    #+#             */
/*   Updated: 2024/05/14 15:57:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_flags	*create_struct(void)
{
	t_flags	*new;

	new = (t_flags *)malloc(sizeof(t_flags));
	if (!new)
		return (NULL);
	new->add = 0;
	new->dot = 0;
	new->hash = 0;
	new->minus = 0;
	new->space = 0;
	new->zero = 0;
	new->len = 0;
	new->zero_offset = 0;
	new->minus_offset = 0;
	new->percision = 0;
	return (new);
}

static void	count_flags(t_flags *flags, char *str, size_t *i)
{
	if (str[*i] == '+')
		flags->add = 1;
	else if (str[*i] == ' ')
		flags->space = 1;
	else if (str[*i] == '#')
		flags->hash = 1;
	else if (str[*i] == '-')
	{
		flags->minus_offset = ft_atoi(str + (int)++(*i));
		flags->minus = 1;
		*i += count_num_len(flags->minus_offset);
	}
	else if (str[*i] == '.')
	{
		flags->percision = ft_atoi(str + (int)++(*i));
		flags->dot = 1;
		*i += count_num_len(flags->percision);
	}
	else if (str[*i] == '0')
	{
		flags->zero_offset = ft_atoi(str + (int)++(*i));
		flags->zero = 1;
		*i += count_num_len(flags->zero_offset);
	}
}

t_flags	*check_flags(char *str, size_t *i)
{
	t_flags	*flags;

	flags = create_struct();
	if (!flags)
		return (NULL);
	while (!ft_strchr(CONVERSIONS, str[++(*i)]))
	{
		if (ft_strchr("+ #-.0", str[*i]))
			count_flags(flags, str, i);
		else
		{
			flags->len = ft_atoi(str + (int)*i);
			*i += count_num_len(flags->len);
			//printf("len = %d, i = %zu, num_len = %d\n", flags->len, *i, count_num_len(flags->len));
		}
		//printf("str[i] = %c, i = %zu\n", str[*i], *i);
	}
	printf("percision = %d\nminus = %d\nminus_offset = %d\nzero_offset = %d\nlen = %d\n", flags->percision, flags->minus, flags->minus_offset, flags->zero_offset, flags->len);
	return (flags);
}
