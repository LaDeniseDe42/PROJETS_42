/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:01:26 by qdenizar          #+#    #+#             */
/*   Updated: 2023/03/17 12:45:18 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error_f(char *message, char **argv)
{
	write(2, message, ft_strlen(message));
	ft_printf("%s", argv[1]);
	write(2, "\n", 1);
	exit(1);
}

void	print_error(char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(1);
}

void	print_error_c(char *message, char **argv)
{
	int	i;

	i = 0;
	write(2, message, ft_strlen(message));
	while (argv[2][i])
	{
		write(2, &argv[2][i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

void	print_error_c2(char *message, char **argv)
{
	int	i;

	i = 0;
	write(2, message, ft_strlen(message));
	while (argv[3][i])
	{
		write(2, &argv[3][i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}
