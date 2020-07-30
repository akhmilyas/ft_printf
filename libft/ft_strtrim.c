/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:47:25 by mstoops           #+#    #+#             */
/*   Updated: 2020/05/03 16:51:14 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_chinset(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_find_first(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_chinset(str[i], set))
		i++;
	return (i);
}

static size_t	ft_find_last(char const *str, char const *set)
{
	size_t	i;

	i = ft_strlen(str);
	while (ft_chinset(str[i - 1], set) && i)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	first;
	size_t	last;

	if (!s1)
		return (NULL);
	i = 0;
	first = ft_find_first(s1, set);
	last = ft_find_last(s1, set);
	if (last >= first)
	{
		if (!(str = (char*)malloc(sizeof(char) * (last - first + 1))))
			return (NULL);
		while (first < last)
			str[i++] = s1[first++];
		str[i] = '\0';
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		*str = '\0';
	}
	return (str);
}
