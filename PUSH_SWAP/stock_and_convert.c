/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_and_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:23:05 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/22 10:21:59 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_me_this_shit(char **argv, t_pile *stock)
{
	char	**buffer;
	char	**buff2;
	int		i;
	int		l;
	int		k;

	i = 1;
	k = 0;
	l = 0;
	buff2 = ft_calloc(stock->how_much + 1, sizeof(char *));
	if (!buff2)
		print_error("erreur de malloc", stock);
	if (stock->how_much == 1)
		print_error2(stock, buff2);
	while (argv[i])
	{
		buffer = ft_split(argv[i], ' ');
		while (buffer[k])
			buff2[l++] = buffer[k++];
		i++;
		k = 0;
		free(buffer);
	}
	stock_me_this_shit(buff2, stock);
	free_tab(buff2, NULL);
}

void	stock_me_this_shit(char **bufarg, t_pile *stock)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stock->pile_a1 = ft_calloc(stock->how_much, sizeof(t_pile));
	if (!(stock->pile_a1))
		print_error2(stock, bufarg);
	while (j != stock->how_much)
	{
		stock->pile_a1[i] = ft_atoi(bufarg[j], stock, bufarg);
		i++;
		j++;
	}
}

void	index_me_please(t_pile *stock)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 1;
	stock->pile_a = ft_calloc(sizeof(t_pile), stock->how_much);
	if (!stock->pile_a)
		print_error("L'allocation de la memoire a echoue", stock);
	while (i != stock->how_much)
	{
		while (j != stock->how_much)
		{
			if (stock->pile_a1[i] > stock->pile_a1[j])
			{
				index++;
			}
			stock->pile_a[i] = index;
			j++;
		}
		j = 0;
		index = 1;
		i++;
	}
}
