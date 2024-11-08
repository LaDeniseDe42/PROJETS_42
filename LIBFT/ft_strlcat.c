/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:31 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/11 16:23:18 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	size_t			taille;
	unsigned int	taillesrc;

	if ((!dst || !src) && !dstsize)
		return (0);
	i = ft_strlen(dst);
	j = 0;
	taille = ft_strlen(dst);
	taillesrc = ft_strlen(src);
	if (!dstsize || dstsize < taille)
		return (taillesrc + dstsize);
	while (src[j] != '\0' && (dstsize - 1) > i && dstsize > 0)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	if (dstsize > taille)
		return (taille + taillesrc);
	return (dstsize + taillesrc);
}
