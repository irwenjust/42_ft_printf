/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:12:56 by likong            #+#    #+#             */
/*   Updated: 2024/05/15 10:22:49 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_stat	*create_status(void)
{
	t_stat	*new;

	new = (t_stat *)malloc(sizeof(t_stat));
	if (!new)
		return (NULL);
	new->add = 0;
	new->mark = 0;
	new->slen = 0;
	new->total_len = 0;
}
