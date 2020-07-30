/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:28:37 by mstoops           #+#    #+#             */
/*   Updated: 2020/05/05 15:26:42 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) > len)
		return (NULL);
	if (ft_strlen(needle) == 0 || len == 0)
		return ((char*)haystack);
	while (i + ft_strlen(needle) <= len)
	{
		if (haystack[i] == needle[0] && haystack[i])
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
				return ((char*)(&haystack[i]));
		i++;
	}
	return (NULL);
}
