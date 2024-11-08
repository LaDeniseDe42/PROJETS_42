/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:21:09 by qdenizar          #+#    #+#             */
/*   Updated: 2023/04/06 10:46:46 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//verification anti "     "
bool	argv_with_only_space(char **argv)
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
					return (false);
			k = 0;
		}
		while (argv[i][j])
			j++;
		j = 0;
		i++;
	}
	return (true);
}

//verification 
bool	is_digit_sign_or_space(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (true_or_false(i, j, argv) == false)
				return (false);
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

bool	true_or_false(int i, int j, char **argv)
{
	if (argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1]))
	{
		print_error("a + walking alone in arg");
		return (false);
	}
	if (argv[i][j] == '-')
	{
		print_error("negative arg are not allowed");
		return (false);
	}
	if ((argv[i][j] == '+')
		&& ((ft_isdigit(argv[i][j + 1]) == 0) && (ft_isdigit(argv[i][j
					- 1]) == 1)))
	{
		print_error("error with arg");
		return (false);
	}
	if ((ft_isdigit(argv[i][j]) == 0 && (argv[i][j] != ' ')
			&& (argv[i][j] != '+')) && (argv[i]))
	{
		print_error("sorry but this arg is not allowed");
		return (false);
	}
	return (true);
}

bool	is_empty(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			print_error("empty arg");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_arg(char **argv, int argc)
{
	if (arg_number(argc) == false)
		return (false);
	if (is_digit_sign_or_space(argv) == false)
		return (false);
	if (argv_with_only_space(argv) == false)
	{
		print_error("i want a number, not a space");
		return (false);
	}
	if (is_empty(argv) == false)
		return (false);
	return (true);
}
