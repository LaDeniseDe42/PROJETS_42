/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:38:26 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/10 11:11:39 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findcharlie(char const *s1, char const *set, int a)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1);
	if (a == 2)
	{
		while (i < j)
		{
			if (ft_strchr(set, s1[j - i - 1]) == 0)
				return (j - i);
			i++;
		}
	}
	else if (a == 1)
	{
		while (i < j)
		{
			if (ft_strchr(set, s1[i]) == 0)
				return (i);
			i++;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*cpy;
	int		z;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	begin = findcharlie(s1, set, 1);
	end = findcharlie(s1, set, 2);
	z = 0;
	cpy = (char *)malloc((sizeof(char)) * (end - begin + 1));
	if (cpy == 0)
		return (0);
	while (begin < end)
	{
		cpy[z] = s1[begin];
		begin++;
		z++;
	}
	cpy[z] = '\0';
	return (cpy);
}
