/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:02:20 by videloff          #+#    #+#             */
/*   Updated: 2020/06/15 15:43:43 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *maillon;

	if (!lst)
		return (NULL);
	maillon = (*f)(lst);
	newlst = maillon;
	while (lst->next)
	{
		lst = lst->next;
		if (!(maillon->next = (*f)(lst)))
		{
			free(maillon->next);
			return (NULL);
		}
		maillon = maillon->next;
	}
	return (newlst);
}
