/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:00:27 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/21 15:30:53 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *message, t_pile *stock)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free_tab(stock->pile_char_a, stock->pile_char_b);
	free(stock->pile_a1);
	free(stock->pile_a);
	free(stock->pile_b);
	free(stock);
	exit(1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(char *str, t_pile *stock, char **tab)
{
	int				i;
	long long int	j;
	int				sign;

	i = 0;
	j = 0;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = str[i] - '0' + j * 10;
		i++;
	}
	j = j * sign;
	if (j > 2147483647 || j < -2147483648)
		print_error3("> Int-max ou < int-min DETECTE", stock, tab);
	return ((int)j);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar_fd('-', fd);
		nbl = nbl * -1;
	}
	if (nbl > 9)
	{
		ft_putnbr_fd(nbl / 10, fd);
		ft_putnbr_fd(nbl % 10, fd);
	}
	else
		ft_putchar_fd(nbl + '0', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
