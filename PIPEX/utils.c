/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:17:03 by qdenizar          #+#    #+#             */
/*   Updated: 2023/03/16 15:02:02 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
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
