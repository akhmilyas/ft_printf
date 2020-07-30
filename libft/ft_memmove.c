/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:37:54 by mstoops           #+#    #+#             */
/*   Updated: 2020/05/02 16:01:36 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tempd;
	unsigned char	*temps;

	i = 0;
	tempd = (unsigned char*)dst;
	temps = (unsigned char*)src;
	if ((dst == 0 && src == 0) || len == 0)
		return (dst);
	if (dst > src)
		while (len != 0)
		{
			len--;
			tempd[len] = temps[len];
		}
	else
		while (i < len)
		{
			tempd[i] = temps[i];
			i++;
		}
	return (dst);
}
