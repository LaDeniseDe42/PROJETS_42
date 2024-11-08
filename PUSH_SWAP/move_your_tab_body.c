/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_your_tab_body.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:03:22 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/13 15:07:07 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_one_up_b(t_pile *stock)
{
	int	i;
	int	j;
	int	k;
	int	cpy;

	i = 0;
	j = nb_of_nb_b(stock) - 1;
	k = stock->how_much;
	while (i < j)
	{
		cpy = stock->pile_b[i + 1];
		stock->pile_b[i] = cpy;
		i++;
	}
	stock->pile_b[i] = 0;
}

void	move_one_up_a(t_pile *stock)
{
	int	i;
	int	j;
	int	k;
	int	cpy;

	i = 0;
	j = nb_of_nb_a(stock) - 1;
	k = stock->how_much;
	while (i < j)
	{
		cpy = stock->pile_a[i + 1];
		stock->pile_a[i] = cpy;
		i++;
	}
	stock->pile_a[i] = 0;
}

void	move_one_down_b(t_pile *stock)
{
	int	i;
	int	j;
	int	k;
	int	cpy;

	i = 0;
	j = nb_of_nb_b(stock);
	k = stock->how_much;
	while (j != 0)
	{
		cpy = stock->pile_b[j - 1];
		stock->pile_b[j] = cpy;
		j--;
	}
}

void	move_one_down_a(t_pile *stock)
{
	int	i;
	int	j;
	int	k;
	int	cpy;

	i = 0;
	j = nb_of_nb_a(stock);
	k = stock->how_much;
	while (j != 0)
	{
		cpy = stock->pile_a[j - 1];
		stock->pile_a[j] = cpy;
		j--;
	}
}
