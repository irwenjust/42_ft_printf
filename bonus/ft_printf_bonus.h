/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:18:19 by likong            #+#    #+#             */
/*   Updated: 2024/05/15 11:11:20 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define HEXBASEL "0123456789abcdef"
# define HEXBASEH "0123456789ABCDEF"

typedef struct	s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	add;
	int	zero_offset;
	int	minus_offset;
	int	percision;
	int	len;
} t_flags;

typedef struct	s_stat
{
	int total_len;
	int slen;
	int add;
	int mark;
} t_stat;

# define CONVERSIONS "%cspdiuxX\0"

# define HEXBASEL "0123456789abcdef"
# define HEXBASEH "0123456789ABCDEF"

//tool functions
char	*ft_strchr(char *s, int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	str_length(char *str);
int		count_num_len(int num);

//two struct functions
t_flags	*check_flags(char *str, size_t *i);
t_stat	*create_status(void);

//mainly functions for bonus
int		ft_printf(const char *str, ...);
int		ft_putnbr_bonus(int n, t_flags *flags);
int		ft_putchar_bonus(int c, t_flags *flags);

#endif
