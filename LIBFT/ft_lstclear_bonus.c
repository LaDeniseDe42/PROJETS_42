/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:48:42 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/15 16:33:57 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_i;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lst_i = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_i;
	}
}
