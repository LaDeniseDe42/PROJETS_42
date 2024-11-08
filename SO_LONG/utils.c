/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:37:50 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/25 13:18:47 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	int		i;

	i = 0;
	if (!s1)
		print_error("strdup est loin d'etre dupe");
	mem = (char *)malloc(sizeof(char) * ft_strlen(s1) +1);
	if (!mem)
		return (0);
	while (s1[i] && s1[i] != '\n')
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (i < dstsize - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

int	ft_strlen_sl(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_sl(char *s1, char *s2)
{
	char	*mem;
	int		len1;
	int		len2;

	mem = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (s2);
	else if (s2 == NULL)
		return (s1);
	len1 = ft_strlen_sl(s1);
	len2 = ft_strlen_sl(s2);
	mem = malloc(len1 + len2 + 1);
	if (!(mem))
		return (NULL);
	ft_strlcpy(mem, s1, len1 + 1);
	ft_strlcpy(mem + len1, s2, len2 + 1);
	free(s1);
	s1 = NULL;
	free(s2);
	return (mem);
}
