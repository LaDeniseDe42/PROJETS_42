/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:23:59 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/15 09:46:13 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newtab;
	int		i;

	i = 0;
	if (!s)
		return (0);
	newtab = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newtab)
		return (0);
	while (s[i])
	{
		newtab[i] = f(i, s[i]);
		i++;
	}
	newtab[i] = '\0';
	return (newtab);
}
