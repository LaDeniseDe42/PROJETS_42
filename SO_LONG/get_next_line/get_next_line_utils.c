/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:05:20 by qdenizar          #+#    #+#             */
/*   Updated: 2022/12/20 10:17:17 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*pointeur;
	size_t	i;

	pointeur = (char *)s;
	i = 0;
	while (i < n)
	{
		*pointeur = '\0';
		pointeur++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (0);
	ft_bzero(mem, count * size);
	return (mem);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cpy;
	int		a;
	int		b;

	a = -1;
	b = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!cpy)
		return (NULL);
	while (s1[++a])
		cpy[a] = s1[a];
	while (s2[b])
		cpy[a++] = s2[b++];
	cpy[a] = '\0';
	free_and_zero(&s1);
	return (cpy);
}
