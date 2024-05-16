/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:31:36 by likong            #+#    #+#             */
/*   Updated: 2024/05/16 14:57:38 by likong           ###   ########.fr       */
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
	new->move_len = 0;
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
	else if (str[*i] == '-' && !ft_strchr(CONVERSIONS, str[(*i) + 1]))
		flags->minus = 1;
	else if (str[*i] == '0' && !ft_strchr(CONVERSIONS, str[(*i) + 1]))
		flags->zero = 1;
	i++;
}

static void	get_value(char *str, size_t *i, int *value, va_list elements)
{
	if (str[*i] == '*')
		*value = va_arg(elements, int);
	else
	{
		*value = ft_atoi(str + (int)*i);
		*i += count_num_len(*value);
	}
}

t_flags	*check_flags(char *str, size_t *i, va_list elements)
{
	t_flags	*flags;

	flags = create_struct();
	if (!flags)
		return (NULL);
	while (!ft_strchr(CONVERSIONS, str[++(*i)]))
	{
		if (ft_strchr("+ #-0", str[*i]))
			count_flags(flags, str, i);
		else if ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '*')
			get_value(str, i, &flags->len, elements);
		else if (str[*i] == '.' && ft_strchr(MNUMBER, str[(*i) + 1]))
		{
			(*i)++;
			get_value(str, i, &flags->percision, elements);
		}
	}
	//printf("percision = %d\nminus = %d\nminus_offset = %d\nzero_offset = %d\nlen = %d\nadd = %d\n", flags->percision, flags->minus, flags->minus_offset, flags->zero_offset, flags->len, flags->add);
	return (flags);
}
