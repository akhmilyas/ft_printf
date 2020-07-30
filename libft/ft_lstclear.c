/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoops <mstoops@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:13:31 by mstoops           #+#    #+#             */
/*   Updated: 2020/05/14 17:19:07 by mstoops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*tmp;

	if (lst && (tmp = *lst) && del)
	{
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
			del(prev->content);
			free(prev);
		}
		del(tmp->content);
		free(tmp);
		*lst = NULL;
	}
}
