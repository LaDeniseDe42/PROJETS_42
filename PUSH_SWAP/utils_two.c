/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:38:53 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/21 15:36:19 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbc(char const *s, char separateur)
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

char	*ft_workforme(char const *s, char c, int i)
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

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**tab;

	i = 0;
	if (!s)
		return (0);
	k = 0;
	tab = ft_calloc((ft_nbc(s, c) + 1), sizeof(char *));
	if (!tab)
		free_tab(tab, NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (k < ft_nbc(s, c))
		{
			tab[k] = ft_workforme(s, c, i);
			if (tab[k++] == 0)
				free_tab(tab, NULL);
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}

char	*ft_strchr(char *s, int c)
{
	char			*str;
	int				i;

	str = s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if (str[i] == (char)c)
		return (str + i);
	return (0);
}

void	print_error3(char *message, t_pile *stock, char **tab)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free_tab(stock->pile_char_a, stock->pile_char_b);
	free(stock->pile_a1);
	free(stock->pile_a);
	free(stock->pile_b);
	free(stock);
	free_tab(tab, NULL);
	exit(1);
}
