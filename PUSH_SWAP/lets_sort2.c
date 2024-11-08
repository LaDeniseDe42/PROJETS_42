/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:18:44 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/21 15:40:45 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile *stock)
{
	int	cpy1;
	int	cpy2;
	int	i;
	int	how;

	cpy2 = 0;
	cpy1 = 0;
	i = 0;
	how = 0;
	if (ft_isdigit_exept_0_b(stock, i) == 1)
	{
		cpy1 = stock->pile_b[0];
		if (ft_isdigit_exept_0_a(stock, i) == 0)
		{
			stock->pile_a[0] = cpy1;
			move_one_up_b(stock);
		}
		else if (ft_isdigit_exept_0_a(stock, i) == 1)
		{
			move_one_down_a(stock);
			stock->pile_a[0] = cpy1;
			move_one_up_b(stock);
		}
	}
	ft_printf("pa\n");
}

void	pb(t_pile *stock)
{
	int	cpy1;
	int	cpy2;
	int	i;
	int	how;

	cpy2 = 0;
	cpy1 = 0;
	i = 0;
	how = 0;
	if (ft_isdigit_exept_0_a(stock, i) == 1)
	{
		cpy1 = stock->pile_a[0];
		if (ft_isdigit_exept_0_b(stock, i) == 0)
		{
			stock->pile_b[0] = cpy1;
			move_one_up_a(stock);
		}
		else if (ft_isdigit_exept_0_b(stock, i) == 1)
		{
			move_one_down_b(stock);
			stock->pile_b[0] = cpy1;
			move_one_up_a(stock);
		}
	}
	ft_printf("pb\n");
}

void	ra(t_pile *stock)
{
	int	cpy;
	int	cpy2;
	int	i;
	int	j;

	i = 1;
	j = nb_of_nb_a(stock);
	if (ft_isdigit_exept_0_a(stock, i) == 1)
	{
		cpy = stock->pile_a[0];
		cpy2 = stock->pile_a[j -1];
		move_one_up_a(stock);
		stock->pile_a[j -1] = cpy;
	}
	ft_printf("ra\n");
}

void	rb(t_pile *stock)
{
	int	cpy;
	int	cpy2;
	int	i;
	int	j;

	i = 1;
	j = nb_of_nb_b(stock);
	if (ft_isdigit_exept_0_b(stock, i) == 1)
	{
		cpy = stock->pile_b[0];
		cpy2 = stock->pile_b[j -1];
		move_one_up_b(stock);
		stock->pile_b[j -1] = cpy;
	}
	ft_printf("rb\n");
}

void	rr(t_pile *stock)
{
	ra(stock);
	rb(stock);
	ft_printf("rr\n");
}
