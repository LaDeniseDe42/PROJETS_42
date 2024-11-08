/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:26:39 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/22 10:22:46 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_exept_0_a(t_pile *stock, int i)
{
	if (stock->pile_a[i] >= 1)
		return (1);
	return (0);
}

int	ft_isdigit_exept_0_b(t_pile *stock, int i)
{
	if (stock->pile_b[i] >= 1)
		return (1);
	return (0);
}

int	nb_of_nb_a(t_pile *stock)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (stock->pile_a[i] && ft_isdigit_exept_0_a(stock, i) == 1)
	{
		i++;
	}
	return (i);
}

int	nb_of_nb_b(t_pile *stock)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (stock->pile_b[i] && ft_isdigit_exept_0_b(stock, i) == 1)
	{
		i++;
	}
	return (i);
}
