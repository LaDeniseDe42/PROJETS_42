/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:53:16 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/11 16:22:13 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*need;
	size_t	i;
	size_t	j;

	hay = (char *)haystack;
	need = (char *)needle;
	i = 0;
	j = 0;
	if (!haystack && !len)
		return (0);
	if (need[i] == '\0')
		return (hay);
	while (hay[i] && i < len)
	{
		while (hay[j + i] == need[j] && hay[j + i] != '\0' && i + j < len)
		{
			j++;
		}
		if (need[j] == '\0')
			return (hay + i);
		i++;
		j = 0;
	}
	return (0);
}
