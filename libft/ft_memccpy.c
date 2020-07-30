/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:22:55 by mstoops           #+#    #+#             */
/*   Updated: 2020/05/02 18:30:59 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tempd;
	unsigned char	*temps;
	size_t			i;

	i = 0;
	tempd = (unsigned char*)dst;
	temps = (unsigned char*)src;
	while (i < n)
	{
		tempd[i] = temps[i];
		if (temps[i] == (unsigned char)c)
			return (&tempd[++i]);
		i++;
	}
	return (NULL);
}
