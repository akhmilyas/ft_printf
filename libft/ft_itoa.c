/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:17:14 by mstoops           #+#    #+#             */
/*   Updated: 2020/05/03 19:19:05 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	long int	len;
	long int	negative;
	char		*a;

	negative = (n < 0) ? 1 : 0;
	len = num(n) + negative;
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (negative)
		a[0] = '-';
	a[len--] = '\0';
	while (len >= negative)
	{
		a[len--] = (negative != 0 ? -1 : 1) * (n % 10) + '0';
		n = n / 10;
	}
	return (a);
}
