/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:26:25 by mstoops           #+#    #+#             */
/*   Updated: 2020/07/30 03:08:42 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;
	t_args	parsed;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	res = 0;
	while (*format != '\0')
	{
		if (*format != '%')
			res += write(1, format++, 1);
		else
		{
			format++;
			if (!(ft_put_format(&format, &parsed, &args)))
				return (-1);
			res += parsed.len;
		}
	}
	va_end(args);
	return (res);
}
