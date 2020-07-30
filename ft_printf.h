/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:26:23 by mstoops           #+#    #+#             */
/*   Updated: 2020/07/30 16:20:38 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define FLAG_EMPTY	0b00000000
# define FLAG_MIN	0b00000001
# define FLAG_ZERO	0b00000010
# define FLAG_DOT	0b00000100

typedef struct		s_args
{
	unsigned char	flags;
	unsigned char	type;
	int				width;
	int				acc;
	int				len;
}					t_args;

int					ft_printf(const char *format, ...);
int					ft_put_format(const char **format, t_args *parsed,\
								va_list *args);
void				ft_set_new(t_args *parsed);
void				ft_parse_flags(const char **format, t_args *parsed);
void				ft_parse_width(const char **format, t_args *parsed,\
								va_list *args);
int					ft_parse_acc(const char **format, t_args *parsed,\
								va_list *args);
void				ft_print_format(va_list *args, t_args *parsed);
void				ft_printf_num(long number, t_args *parsed, int base);
void				ft_printf_c(char c, t_args *parsed);
void				ft_printf_s(char *str, t_args *parsed);
void				ft_printf_pointer(size_t number, t_args *parsed, int base);

int					ft_find_type_format(char symbol);
void				ft_printf_putchar(int c, int length);
int					ft_length_number(long number, int base);
void				ft_printf_putnbr(long number, unsigned int base,\
									t_args *parsed);
void				ft_putstr_ft_with_len(char *s, int fd, int length);

#endif
