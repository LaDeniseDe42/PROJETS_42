/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:42:51 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/22 10:21:08 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile *stock)
{
	int	cpy;
	int	i;
	int	j;

	i = 1;
	j = nb_of_nb_a(stock);
	if (ft_isdigit_exept_0_a(stock, i) == 1)
	{
		cpy = stock->pile_a[j -1];
		move_one_down_a(stock);
		stock->pile_a[0] = cpy;
		stock->pile_a[j] = 0;
	}
	ft_printf("rra\n");
}

void	rrb(t_pile *stock)
{
	int	cpy;
	int	i;
	int	j;

	i = 1;
	j = nb_of_nb_b(stock);
	if (ft_isdigit_exept_0_b(stock, i) == 1)
	{
		cpy = stock->pile_b[j -1];
		move_one_down_b(stock);
		stock->pile_b[0] = cpy;
		stock->pile_b[j] = 0;
	}
	ft_printf("rrb\n");
}

void	rrr(t_pile *stock)
{
	rra(stock);
	rrb(stock);
	ft_printf("rrr\n");
}

void	do_the_while_of_sort(t_pile *stock, int i, int j, int len)
{
	while (j < len)
	{
		if (((stock->pile_a[0] >> i) & 1) == 1)
			ra(stock);
		else
			pb(stock);
		j++;
	}
}

void	do_the_while_of_sort2(t_pile *stock, int i, int j, int len)
{
	while (j < len)
	{
		if (((stock->pile_b[0] >> i) & 1) == 0)
			rb(stock);
		else
			pa(stock);
		j++;
	}
}
