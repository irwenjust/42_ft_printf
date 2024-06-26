/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:31:39 by likong            #+#    #+#             */
/*   Updated: 2024/05/10 10:13:42 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

# define HEXBASEL "0123456789abcdef"
# define HEXBASEH "0123456789ABCDEF"

int		ft_putchar(int c);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
size_t	str_length(char *str);
int		ft_putpoint(void *str);
int		ft_putnbr(int n);
int		ft_putnum_unsign(unsigned int n);
int		ft_puthex(int nbr, char *str);

#endif