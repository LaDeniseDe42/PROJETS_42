/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:16:54 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/04 14:54:37 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pointeur;
	size_t			i;

	pointeur = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		*pointeur = '\0';
		pointeur++;
		i++;
	}
}
