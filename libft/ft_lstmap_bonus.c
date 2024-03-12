/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailism <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:30:40 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/22 19:22:00 by mailism          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	t_list	*set;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	new_obj = NULL;
	while (lst != NULL)
	{
		set = f(lst->content);
		new_obj = ft_lstnew(set);
		if (new_obj == NULL)
		{
			del(set);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}
