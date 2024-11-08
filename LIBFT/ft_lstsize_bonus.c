/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:26:48 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/15 12:26:50 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	compt;
	t_list	*lst_temp;

	compt = 0;
	if (!lst)
		return (0);
	lst_temp = lst;
	while (lst_temp)
	{
		lst_temp = lst_temp->next;
		compt++;
	}
	return (compt);
}
