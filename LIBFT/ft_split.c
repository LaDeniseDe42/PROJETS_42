/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:17:13 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/10 10:37:35 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbc(char const *s, char separateur)
{
	int	nbc;
	int	i;
	int	j;

	i = 0;
	j = 0;
	nbc = 0;
	while (s[j])
	{
		if (s[j] != separateur && i == 0)
		{
			i = 1;
			nbc++;
		}
		else if (s[j] == separateur)
			i = 0;
		j++;
	}
	return (nbc);
}

static char	*ft_workforme(char const *s, char c, int i)
{
	int		j;
	char	*tab;
	int		k;

	j = i;
	k = 0;
	while (s[j] && s[j] != c)
		j++;
	tab = malloc(sizeof(char) * (j - i + 1));
	if (!tab)
		return (0);
	while (s[i] && i < j)
		tab[k++] = s[i++];
	tab[k] = '\0';
	return (tab);
}

static	void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		k;
	char		**tab;

	i = 0;
	if (!s)
		return (0);
	k = 0;
	tab = ft_calloc((ft_nbc(s, c) + 1), sizeof(char *));
	if (!tab)
		return (free_tab(tab));
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (k < ft_nbc(s, c))
		{
			tab[k] = ft_workforme(s, c, i);
			if (tab[k++] == 0)
				return (free_tab(tab));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}
