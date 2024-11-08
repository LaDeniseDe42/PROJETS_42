/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:40:54 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/22 10:21:33 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_numbers(t_pile *stock)
{
	if (stock->pile_a[0] == 1 && stock->pile_a[1] == 3 && stock->pile_a[2] == 2)
	{
		rra(stock);
		sa(stock);
	}
	if (stock->pile_a[0] == 2 && stock->pile_a[1] == 1 && stock->pile_a[2] == 3)
		sa(stock);
	if (stock->pile_a[0] == 3 && stock->pile_a[1] == 1 && stock->pile_a[2] == 2)
		ra(stock);
	if (stock->pile_a[0] == 3 && stock->pile_a[1] == 2 && stock->pile_a[2] == 1)
	{
		sa(stock);
		rra(stock);
	}
	if (stock->pile_a[0] == 2 && stock->pile_a[1] == 3 && stock->pile_a[2] == 1)
		rra(stock);
}

void	sort_3_numbers_bis(t_pile *stock)
{
	if (stock->pile_a[0] == 3 && stock->pile_a[1] == 5 && stock->pile_a[2] == 4)
	{
		rra(stock);
		sa(stock);
	}
	if (stock->pile_a[0] == 4 && stock->pile_a[1] == 3 && stock->pile_a[2] == 5)
		sa(stock);
	if (stock->pile_a[0] == 5 && stock->pile_a[1] == 3 && stock->pile_a[2] == 4)
		ra(stock);
	if (stock->pile_a[0] == 5 && stock->pile_a[1] == 4 && stock->pile_a[2] == 3)
	{
		sa(stock);
		rra(stock);
	}
	if (stock->pile_a[0] == 4 && stock->pile_a[1] == 5 && stock->pile_a[2] == 3)
		rra(stock);
}

void	sort_4_or_5_numbers(t_pile *stock)
{
	while (stock->pile_a[0] != 1 && stock->pile_a[0] != 2)
		ra(stock);
	if (stock->pile_a[0] == 1 || stock->pile_a[0] == 2)
		pb(stock);
	while (stock->pile_a[0] != 1 && stock->pile_a[0] != 2)
		ra(stock);
	if (stock->pile_a[0] == 1 || stock->pile_a[0] == 2)
		pb(stock);
	if (stock->pile_b[0] != 2)
		rb(stock);
	if (stock->how_much == 5)
		sort_3_numbers_bis(stock);
	if (stock->how_much == 4)
	{
		if (stock->pile_a[0] > stock->pile_a[1])
			ra(stock);
	}
	pa(stock);
	pa(stock);
}

void	sort_more_and_more(t_pile *stock)
{
	int	i;
	int	j;
	int	max_num;
	int	max_bits;
	int	len;

	i = 0;
	j = 0;
	max_num = nb_of_nb_a(stock);
	max_bits = 0;
	while (max_num >> max_bits != 0)
		max_bits++;
	while (i < max_bits)
	{
		len = nb_of_nb_a(stock);
		j = 0;
		do_the_while_of_sort(stock, i, j, len);
		len = nb_of_nb_b(stock);
		j = 0;
		do_the_while_of_sort2(stock, i, j, len);
		i++;
	}
	while (nb_of_nb_b(stock) > 0)
		pa(stock);
}
