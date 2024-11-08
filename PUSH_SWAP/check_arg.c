/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:20:47 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/22 10:28:17 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_digit_sign_or_space(char **argv, t_pile *stock)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1]))
				print_error("un + ou un - se balade seul", stock);
			if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
				print_error("un + ou un - se balade seul", stock);
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& ((ft_isdigit(argv[i][j + 1]) == 0) && (ft_isdigit(argv[i][j
							- 1]) == 1)))
				print_error("une erreur de ce type est presente 1-3", stock);
			if ((ft_isdigit(argv[i][j]) == 0 && (argv[i][j] != ' ')
					&& (argv[i][j] != '-') && (argv[i][j] != '+')) && (argv[i]))
				print_error("des cara non autorise sont present.", stock);
			j++;
		}
		j = 0;
		i++;
	}
}

int	argv_with_only_space(char **argv)
{
	int	i;
	int	j;
	int	k;
	int	b;

	i = 1;
	j = 0;
	k = 0;
	b = 0;
	while (argv[i])
	{
		if (argv[i][k] == ' ')
		{
			while (argv[i][k++] == ' ')
				if (argv[i][k + 1] == '\0')
					return (b + 1);
			k = 0;
		}
		while (argv[i][j])
			j++;
		j = 0;
		i++;
	}
	return (b);
}

void	double_not_pass(t_pile *stock)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = stock->how_much;
	while (i != k)
	{
		while (j != k)
		{
			if (stock->pile_a1[i] == stock->pile_a1[j])
				print_error("I never allow you to put double in my list",
					stock);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}
