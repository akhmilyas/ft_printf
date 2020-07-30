/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:48:55 by mstoops           #+#    #+#             */
/*   Updated: 2020/07/30 16:08:54 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_pointer(size_t number, size_t base)
{
	int	length;

	length = 0;
	while (number > base - 1)
	{
		length++;
		number /= base;
	}
	length++;
	return (length);
}

static void	ft_pointer_null(t_args *parsed)
{
	if (parsed->width == 0)
		parsed->width = 2;
	if (parsed->width < parsed->acc + 2)
		parsed->width = parsed->acc + 2;
	if (parsed->flags & FLAG_MIN)
	{
		ft_putstr_ft_with_len("0x", 1, 2);
		ft_printf_putchar('0', parsed->acc);
		ft_printf_putchar(' ', parsed->width - parsed->acc - 2);
	}
	else
	{
		ft_printf_putchar(' ', parsed->width - parsed->acc - 2);
		ft_putstr_ft_with_len("0x", 1, 2);
		ft_printf_putchar('0', parsed->acc);
	}
	parsed->len = parsed->width;
}

static void	ft_pointer_with_acc(size_t number, t_args *parsed, int base)
{
	if (parsed->acc < ft_length_pointer(number, base))
		parsed->acc = ft_length_pointer(number, base);
	if (parsed->width > parsed->acc)
		parsed->width = parsed->width - 2;
	if (parsed->width < parsed->acc)
		parsed->width = parsed->acc;
	if (parsed->flags & FLAG_MIN)
	{
		ft_putstr_ft_with_len("0x", 1, 2);
		ft_printf_putchar('0', parsed->acc - ft_length_pointer(number, base));
		ft_printf_putnbr(number, base, parsed);
		ft_printf_putchar(' ', parsed->width - parsed->acc);
	}
	else
	{
		ft_printf_putchar(' ', parsed->width - parsed->acc);
		ft_putstr_ft_with_len("0x", 1, 2);
		ft_printf_putchar('0', parsed->acc - ft_length_pointer(number, base));
		ft_printf_putnbr(number, base, parsed);
	}
	parsed->len = parsed->width + 2;
}

static void	ft_pointer_without_acc(size_t number, t_args *parsed, int base)
{
	char	space;
	int		nl;

	nl = ft_length_pointer(number, base);
	if (parsed->flags & FLAG_ZERO)
		space = '0';
	else
		space = ' ';
	if (nl + 2 < parsed->width)
		parsed->acc = parsed->width - nl - 2;
	if (parsed->flags & FLAG_MIN)
	{
		ft_putstr_ft_with_len("0x", 1, 2);
		ft_printf_putnbr(number, base, parsed);
		ft_printf_putchar(space, parsed->acc);
	}
	else
	{
		ft_printf_putchar(space, parsed->acc);
		ft_putstr_ft_with_len("0x", 1, 2);
		ft_printf_putnbr(number, base, parsed);
	}
	parsed->len = parsed->acc + nl + 2;
}

void		ft_printf_pointer(size_t number, t_args *parsed, int base)
{
	if (parsed->flags & FLAG_DOT)
	{
		if (number == 0)
			return (ft_pointer_null(parsed));
		ft_pointer_with_acc(number, parsed, base);
	}
	else
		ft_pointer_without_acc(number, parsed, base);
}
