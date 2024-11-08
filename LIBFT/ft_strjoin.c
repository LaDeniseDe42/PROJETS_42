/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:54:59 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/09 18:13:58 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!cpy)
		return (0);
	while (s1[a])
	{
		cpy[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		cpy[a] = s2[b];
		a++;
		b++;
	}
	cpy[a] = '\0';
	return (cpy);
}
