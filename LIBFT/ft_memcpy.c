/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:40:21 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/07 11:10:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*clonesource;
	unsigned char	*clonedestination;
	size_t			i;

	clonesource = (unsigned char *)src;
	clonedestination = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*clonedestination = *clonesource;
		clonedestination++;
		clonesource++;
		i++;
	}
	return (dst);
}
