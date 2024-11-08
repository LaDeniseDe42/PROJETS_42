/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:10:22 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/21 15:36:36 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		return (0);
	if (mem)
		ft_bzero(mem, count * size);
	return (mem);
}

void	print_error2(t_pile *stock, char **buff2)
{
	free(buff2);
	free_tab(stock->pile_char_a, stock->pile_char_b);
	free(stock->pile_a1);
	free(stock->pile_a);
	free(stock->pile_b);
	free(stock);
	exit(1);
}

void	free_tab(char **tab, char **tab2)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	i = 0;
	if (tab2)
	{
		while (tab2[i])
		{
			free(tab2[i]);
			i++;
		}
		free(tab2);
	}
}

void	free_my_big_tab_of_int_stars(int *tab, int *tab2, int *tab3)
{
	free(tab);
	free(tab2);
	free(tab3);
}
