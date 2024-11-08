/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:38:21 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/11 13:43:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	j;
	size_t	length;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	length = ft_strlen(s + start);
	if (length < len)
		cpy = (char *)malloc(sizeof(char) * (length + 1));
	else
		cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (0);
	while (i != start)
		i++;
	while (j < len && s[i])
		cpy[j++] = s[i++];
	cpy[j] = '\0';
	return (cpy);
}
