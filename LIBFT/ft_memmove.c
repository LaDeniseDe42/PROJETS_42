/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:08:22 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/16 09:43:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*clonedst;
	unsigned char	*clonesrc;
	size_t			i;

	clonedst = (unsigned char *)dst;
	clonesrc = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (clonesrc < clonedst)
	{
		while (len-- > 0)
			clonedst[len] = clonesrc[len];
	}
	else
	{
		while (i < len)
		{
			clonedst[i] = clonesrc[i];
			i++;
		}
	}
	return (dst);
}
