/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:08:05 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/09 18:00:30 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pointeur;

	i = 0;
	pointeur = (unsigned char *) b;
	while (i < len)
	{
		*pointeur = c;
		pointeur++;
		i++;
	}
	return (b);
}
