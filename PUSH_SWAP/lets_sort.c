/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:19:11 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/27 14:15:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lets_the_game_begin(t_pile *stock)
{
	stock->pile_b = ft_calloc(sizeof(t_pile), stock->how_much);
	if (!stock->pile_b)
	{
		free(stock);
		exit(0);
	}
	i_hope_this_isnt_already_sort(stock);
	if (stock->how_much == 2)
		sa(stock);
	else if (stock->how_much == 3)
		sort_3_numbers(stock);
	else if (stock->how_much == 4 || stock->how_much == 5)
		sort_4_or_5_numbers(stock);
	else
		sort_more_and_more(stock);
	free_tab(stock->pile_char_a, stock->pile_char_b);
	free_my_big_tab_of_int_stars(stock->pile_a1, stock->pile_a, stock->pile_b);
}

void	i_hope_this_isnt_already_sort(t_pile *stock)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (stock->pile_a[i] == j)
	{
		if (stock->pile_a[i + 1] == '\0')
		{
			free_tab(stock->pile_char_a, stock->pile_char_b);
			free_my_big_tab_of_int_stars(stock->pile_a1, stock->pile_a,
				stock->pile_b);
			free(stock);
			exit(0);
		}
		i++;
		j++;
	}
}

void	sa(t_pile *stock)
{
	int	cpy1;
	int	cpy2;

	cpy2 = 0;
	cpy1 = 0;
	if (nb_of_nb_a(stock) >= 2)
	{
		cpy1 = stock->pile_a[0];
		cpy2 = stock->pile_a[1];
		stock->pile_a[0] = cpy2;
		stock->pile_a[1] = cpy1;
	}
	ft_printf("sa\n");
}

void	sb(t_pile *stock)
{
	int	cpy1;
	int	cpy2;

	cpy2 = 0;
	cpy1 = 0;
	if (nb_of_nb_b(stock) >= 2)
	{
		cpy1 = stock->pile_b[0];
		cpy2 = stock->pile_b[1];
		stock->pile_b[0] = cpy2;
		stock->pile_b[1] = cpy1;
	}
	ft_printf("sb\n");
}

void	ss(t_pile *stock)
{
	int	cpy1;
	int	cpy2;
	int	cpy3;
	int	cpy4;

	cpy2 = 0;
	cpy1 = 0;
	cpy3 = 0;
	cpy4 = 0;
	if (nb_of_nb_a(stock) >= 2)
	{
		cpy1 = stock->pile_a[0];
		cpy2 = stock->pile_a[1];
		stock->pile_a[0] = cpy2;
		stock->pile_a[1] = cpy1;
	}
	if (nb_of_nb_b(stock) >= 2)
	{
		cpy3 = stock->pile_b[0];
		cpy4 = stock->pile_b[1];
		stock->pile_b[0] = cpy4;
		stock->pile_b[1] = cpy3;
	}
	ft_printf("ss\n");
}
