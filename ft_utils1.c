/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:43:05 by mstoops           #+#    #+#             */
/*   Updated: 2020/07/30 15:36:41 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_type_format(char symbol)
{
	char	*for_find;

	for_find = "cspdiuxX%";
	while (*for_find)
	{
		if (*for_find == symbol)
			return (1);
		for_find++;
	}
	return (0);
}

void	ft_printf_putchar(int c, int length)
{
	while (length != 0)
	{
		write(1, &c, 1);
		length--;
	}
}

int		ft_length_number(long number, int base)
{
	int	length;

	length = 0;
	if (number < 0)
	{
		length++;
		number *= -1;
	}
	while (number > base - 1)
	{
		length++;
		number /= base;
	}
	length++;
	if (number < 0)
		length++;
	return (length);
}

void	ft_printf_putnbr(long number, unsigned int base, t_args *parsed)
{
	char			symb;
	unsigned long	m;
	char			cp;

	cp = parsed->type == 'X' ? 'A' : 'a';
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	m = (unsigned long)number;
	if (m >= base)
	{
		ft_printf_putnbr(m / base, base, parsed);
		symb = (m % base) + (m % base > 9 ? cp - 10 : '0');
		write(1, &symb, 1);
	}
	if ((m > 0 || m == 0) && m <= base - 1)
	{
		symb = m + (m % base > 9 ? cp - 10 : '0');
		write(1, &symb, 1);
	}
}

void	ft_putstr_ft_with_len(char *s, int fd, int length)
{
	if (!s)
		return ;
	write(fd, s, length);
}
