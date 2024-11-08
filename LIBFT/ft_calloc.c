/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:38:54 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/07 12:56:29 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		return (0);
	if (mem)
		ft_bzero(mem, count * size);
	return (mem);
}
