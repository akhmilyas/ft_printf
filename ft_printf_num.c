/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:53:51 by mstoops           #+#    #+#             */
/*   Updated: 2020/07/30 04:04:27 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_sign(long *number)
{
	if (*number < 0)
	{
		ft_putchar_fd('-', 1);
		*number = -(*number);
	}
}

static void		ft_number_with_acc_prep(long number, t_args *parsed, int base)
{
	if ((parsed->flags & FLAG_ZERO) && number > -1 && parsed->acc < 0)
		parsed->acc = parsed->width;
	else if (parsed->acc < 0 && number < 0 && (parsed->flags & FLAG_ZERO))
		parsed->acc = parsed->width - 1;
	if (ft_length_number(number, base) <= parsed->acc)
		if (number < 0)
		{
			parsed->acc++;
			if (parsed->width < parsed->acc)
				parsed->width++;
		}
	if (parsed->acc < ft_length_number(number, base))
		parsed->acc = ft_length_number(number, base);
	if (parsed->width < parsed->acc && parsed->acc > 0)
		parsed->width = parsed->acc;
}

static void		ft_number_with_acc(long number, t_args *parsed, int base)
{
	int	nl;

	nl = ft_length_number(number, base);
	ft_number_with_acc_prep(number, parsed, base);
	if (parsed->flags & FLAG_MIN)
	{
		ft_sign(&number);
		ft_printf_putchar('0', parsed->acc - nl);
		ft_printf_putnbr(number, base, parsed);
		ft_printf_putchar(' ', parsed->width - parsed->acc);
	}
	else
	{
		ft_printf_putchar(' ', parsed->width - parsed->acc);
		ft_sign(&number);
		ft_printf_putchar('0', parsed->acc - nl);
		ft_printf_putnbr(number, base, parsed);
	}
	parsed->len = parsed->width;
}

void			ft_number_without_acc(long number, t_args *parsed, int base)
{
	char	space;
	int		nl;

	nl = ft_length_number(number, base);
	if (parsed->flags & FLAG_ZERO)
	{
		space = '0';
		ft_sign(&number);
	}
	else
		space = ' ';
	if (nl < parsed->width)
		parsed->acc = parsed->width - nl;
	if (parsed->flags & FLAG_MIN)
	{
		ft_printf_putnbr(number, base, parsed);
		ft_printf_putchar(space, parsed->acc);
	}
	else
	{
		ft_printf_putchar(space, parsed->acc);
		ft_printf_putnbr(number, base, parsed);
	}
	parsed->len = parsed->acc + nl;
}

void			ft_printf_num(long number, t_args *parsed, int base)
{
	if (parsed->flags & FLAG_DOT)
	{
		if (!number && !parsed->acc)
		{
			ft_printf_putchar(' ', parsed->width);
			parsed->len = parsed->width;
			return ;
		}
		ft_number_with_acc(number, parsed, base);
	}
	else
		ft_number_without_acc(number, parsed, base);
}
