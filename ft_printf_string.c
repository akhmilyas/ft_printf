/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:20:36 by mstoops           #+#    #+#             */
/*   Updated: 2020/07/30 15:43:58 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_c(char c, t_args *parsed)
{
	char	space;

	if (parsed->flags & FLAG_ZERO)
		space = '0';
	else
		space = ' ';
	if (parsed->width == 0)
		parsed->width = 1;
	if (parsed->flags & FLAG_MIN)
	{
		ft_putchar_fd(c, 1);
		ft_printf_putchar(space, parsed->width - 1);
	}
	else
	{
		ft_printf_putchar(space, parsed->width - 1);
		ft_putchar_fd(c, 1);
	}
	parsed->len = parsed->width;
}

static void	ft_string_with_acc(char *str, t_args *parsed)
{
	if ((int)ft_strlen(str) < parsed->acc || parsed->acc < 0)
		parsed->acc = ft_strlen(str);
	if (parsed->width < parsed->acc)
		parsed->width = parsed->acc;
	if (parsed->flags & FLAG_MIN)
	{
		ft_putstr_ft_with_len(str, 1, parsed->acc);
		ft_printf_putchar(' ', parsed->width - parsed->acc);
	}
	else
	{
		ft_printf_putchar(' ', parsed->width - parsed->acc);
		ft_putstr_ft_with_len(str, 1, parsed->acc);
	}
	parsed->len = parsed->width;
}

static void	ft_string_without_acc(char *str, t_args *parsed)
{
	char	space;

	if (parsed->flags & FLAG_DOT)
		space = '0';
	else
		space = ' ';
	if ((int)ft_strlen(str) < parsed->width)
		parsed->acc = parsed->width - ft_strlen(str);
	if (parsed->flags & FLAG_MIN)
	{
		ft_putstr_ft_with_len(str, 1, ft_strlen(str));
		ft_printf_putchar(space, parsed->acc);
	}
	else
	{
		ft_printf_putchar(space, parsed->acc);
		ft_putstr_ft_with_len(str, 1, ft_strlen(str));
	}
	parsed->len = parsed->acc + ft_strlen(str);
}

void		ft_printf_s(char *str, t_args *parsed)
{
	if (str == NULL)
		str = "(null)";
	if (parsed->flags & FLAG_DOT)
		ft_string_with_acc(str, parsed);
	else
		ft_string_without_acc(str, parsed);

}
