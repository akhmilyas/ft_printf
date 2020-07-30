/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:41:10 by mstoops           #+#    #+#             */
/*   Updated: 2020/07/30 02:50:56 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_format(va_list *args, t_args *parsed)
{
	if (parsed->type == 'c')
		//ft_printf_c((char)va_arg(*args, int), parsed);
		return ;
	// else if (parsed->type == 's')
	// 	ft_printf_s(va_arg(*args, char *), parsed);
	else if (parsed->type == 'i' || parsed->type == 'd')
		ft_printf_num((long)va_arg(*args, int), parsed, 10);
	else if (parsed->type == 'u')
		ft_printf_num((long)va_arg(*args, unsigned int), parsed, 10);
	else if (parsed->type == 'x' || parsed->type == 'X')
		ft_printf_num((long)va_arg(*args, unsigned int), parsed, 16);
	// else if (parsed->type == 'p')
	// 	ft_printf_pointer(va_arg(*args, size_t), parsed, 16);
	// else if (parsed->type == '%')
	// 	ft_printf_c("%", parsed);
}
