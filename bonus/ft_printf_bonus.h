/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:18:19 by likong            #+#    #+#             */
/*   Updated: 2024/05/21 09:29:03 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_flags
{
	int	minus;
	int	zero;
	int	hash;
	int	space;
	int	add;
	int	percision;
	int	len;
	int	slen;
	int move_len;
	int dot;
	int neg;
	int nul;
} t_flags;

typedef struct	s_stat
{
	int total_len;
	int slen;
	int add;
	int mark;
} t_stat;

# define CONVERSIONS "%cspdiuxX\0"
# define MNUMBER "0123456789*"

# define DECIMEL "0123456789"
# define HEXBASEL "0123456789abcdef"
# define HEXBASEH "0123456789ABCDEF"

//tool functions
char	*ft_strchr(char *s, int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_itoa_p(unsigned int num);
size_t	str_length(char *str);
int		count_num_len(int num);
int		put_char(char c);
int		get_number_size(unsigned long long num, int base_size);
int		print_number_base(unsigned long long num, char *base);
char	*ft_substr(char *s, unsigned int start, size_t len);

//two struct functions
t_flags	check_flags(char *str, size_t *i, va_list elements);
t_stat	create_status(void);

//mainly functions for bonus
int		ft_printf(const char *str, ...);
int		ft_putnbr_bonus(int n, t_flags *flags);
int		ft_putchar_bonus(int c, t_flags *flags);
int		ft_putstr_bonus(char *str, t_flags *flags);
int		ft_putpoint_bonus(void *str, t_flags *flags);
int		ft_putunbr_bonus(unsigned int n, t_flags *flags);
int		ft_puthex_bonus(int num, char *str, t_flags *flags);

#endif
