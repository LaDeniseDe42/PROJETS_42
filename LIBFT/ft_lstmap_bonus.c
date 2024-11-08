/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:22:36 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/17 09:39:46 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_but_not_lstnew(void *content, void (*del)(void *))
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(*ptr));
	if (!ptr)
	{
		del(content);
		return (0);
	}
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*save_tmp;

	if (!lst || !f || !del)
		return (0);
	tmp = ft_lstnew_but_not_lstnew(f(lst->content), del);
	if (!tmp)
		return (0);
	save_tmp = tmp;
	lst = lst->next;
	while (lst != NULL)
	{
		save_tmp = ft_lstnew_but_not_lstnew(f(lst->content), del);
		if (!save_tmp)
		{
			ft_lstclear(&save_tmp, del);
			ft_lstclear(&tmp, del);
		}
		lst = lst->next;
		ft_lstadd_back(&tmp, save_tmp);
	}
	return (tmp);
}
