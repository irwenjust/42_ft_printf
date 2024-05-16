/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:18:00 by likong            #+#    #+#             */
/*   Updated: 2024/05/16 18:56:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_type(char *str, size_t *i, va_list elements)
{
	t_flags *flags;

	flags = check_flags(str, i, elements);
	if (str[*i] == 'c')
		return (ft_putchar_bonus(va_arg(elements, int), flags));
	else if (str[*i] == 's')
		return (ft_putstr_bonus(va_arg(elements, char *), flags));
	/*else if (str[*i] == 'p')
		return (ft_putpoint(va_arg(elements, void *)));
	*/else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_putnbr_bonus(va_arg(elements, int), flags));
	/*else if (str[*i] == 'u')
		return (ft_putnum_unsign(va_arg(elements, unsigned int)));
	else if (str[*i] == 'x')
		return (ft_puthex(va_arg(elements, int), HEXBASEL));
	else if (str[*i] == 'X')
		return (ft_puthex(va_arg(elements, int), HEXBASEH));
	else if (str[*i] == '%')
		return (write(1, "%", 1));
	*/
	free(flags);
	return (0);
}

static int	next_func(char *str, va_list elements, size_t len)
{
	size_t	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (len);
			j = check_type(str, &i, elements);
			if (j == -1)
				return (-1);
			len += (size_t)j;
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf_bonus(const char *str, ...)
{
	va_list	elements;
	size_t	len;

	len = 0;
	va_start(elements, str);
	len = next_func((char *)str, elements, len);
	va_end(elements);
	return (len);
}
