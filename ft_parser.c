/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:04:54 by mstoops           #+#    #+#             */
/*   Updated: 2020/07/30 04:12:04 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_new(t_args *parsed)
{
	parsed->flags = FLAG_EMPTY;
	parsed->type = '\0';
	parsed->len = 0;
	parsed->acc = 0;
	parsed->width = 0;
}

void	ft_parse_flags(const char **format, t_args *parsed)
{
	while (**format)
	{
		if (**format == '0')
			parsed->flags |= FLAG_ZERO;
		else if (**format == '-')
			parsed->flags |= FLAG_MIN;
		else
			break ;
		(*format)++;
	}
}

void	ft_parse_width(const char **format, t_args *parsed, va_list *args)
{
	if (**format != '*')
	{
		parsed->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else
	{
		parsed->width = va_arg(*args, int);
		(*format)++;
		if (parsed->width < 0)
		{
			parsed->flags |= FLAG_MIN;
			if (parsed->flags & FLAG_ZERO)
				parsed->flags &= ~FLAG_ZERO;
			parsed->width = -parsed->width;
		}
	}
}

int		ft_parse_acc(const char **format, t_args *parsed, va_list *args)
{
	parsed->flags |= FLAG_DOT;
	(*format)++;
	if (ft_isalpha(**format))
		return (1);
	if (**format == '*')
	{
		parsed->acc = va_arg(*args, int);
		(*format)++;
		if (parsed->acc < 0)
		{
			parsed->flags &= ~FLAG_DOT;
			parsed->acc = 0;
		}
		return (1);
	}
	parsed->acc = ft_atoi(*format);
	if (parsed->acc < 0)
	{
		parsed->flags &= ~FLAG_DOT;
		parsed->acc = 0;
		return (0);
	}
	while (ft_isdigit(**format))
		(*format)++;
	return (1);
}

int		ft_put_format(const char **format, t_args *parsed, va_list *args)
{
	ft_set_new(parsed);
	ft_parse_flags(format, parsed);
	ft_parse_width(format, parsed, args);
	if (**format == '.' && !(ft_parse_acc(format, parsed, args)))
		return (0);
	if (!(ft_find_type_format(**format)))
		return (1);
	else
		parsed->type = **format;
	(*format)++;
	if (parsed->flags & FLAG_ZERO && parsed->flags & FLAG_MIN)
		parsed->flags &= ~FLAG_ZERO;
	ft_print_format(args, parsed);
	return (1);
}
