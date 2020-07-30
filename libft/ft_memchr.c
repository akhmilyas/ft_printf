/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:04:28 by mstoops           #+#    #+#             */
/*   Updated: 2020/05/02 16:19:43 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	stop;

	i = 0;
	str = (unsigned char*)s;
	stop = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == stop)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
