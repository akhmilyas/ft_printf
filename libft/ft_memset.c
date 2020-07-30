/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:25:48 by mstoops           #+#    #+#             */
/*   Updated: 2020/05/02 16:34:08 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*tmp;
	unsigned char	const_byte;

	i = 0;
	tmp = (char*)b;
	const_byte = (unsigned char)c;
	while (i < len)
		tmp[i++] = const_byte;
	return (b);
}
