/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_much_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:29:17 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/22 10:23:08 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_much_number(char **argv, int argc)
{
	t_la_pour_gratter_deux_ligne	w;	

	w.i = 1;
	w.j = 0;
	w.how_much = 0;
	while (w.i < argc)
	{
		if ((ft_isdigit(argv[w.i][w.j]) == 1 || argv[w.i][w.j] == '+'
				|| argv[w.i][w.j] == '-') && argv[w.i][w.j])
			w.j++;
		if (argv[w.i][w.j] == ' ')
		{
			while (argv[w.i][w.j] == ' ' && argv[w.i][w.j])
				w.j++;
			if (how_much_number_two(argv, w.i, w.j) == 1)
				w.how_much++;
		}
		if (argv[w.i][w.j] == '\0')
		{
			w.i++;
			w.how_much++;
			w.j = 0;
		}
	}
	return (w.how_much);
}

int	how_much_number_two(char **argv, int i, int j)
{
	while (argv[i][j] == ' ' && argv[i][j])
		j++;
	if ((ft_isdigit(argv[i][j]) == 1 || argv[i][j] == '-' || argv[i][j] == '+')
		&& argv[i][j])
	{
		if (read_my_back(argv, i, j - 1) == 1)
			return (1);
	}
	return (0);
}

int	read_my_back(char **argv, int i, int j)
{
	while (argv[i][j] == ' ' && j != 0)
	{
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j--;
		if (ft_isdigit(argv[i][j]) == 1)
			return (1);
		j--;
	}
	if (ft_isdigit(argv[i][j]) == 1)
		return (1);
	return (0);
}
