/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:02:11 by likong            #+#    #+#             */
/*   Updated: 2024/05/20 20:50:20 by likong           ###   ########.fr       */
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
