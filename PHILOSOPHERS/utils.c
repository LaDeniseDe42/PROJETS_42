/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:57:44 by qdenizar          #+#    #+#             */
/*   Updated: 2023/03/28 12:48:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

int	ft_atoi(char *str)
{
	int				i;
	long long int	j;

	i = 0;
	j = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = str[i] - '0' + j * 10;
		i++;
	}
	if (j > 2147483647)
	{
		print_error("> Int-max DETECTE");
		return (0);
	}
	return ((int)j);
}

char	*ft_itoa(int i)
{
	int		size;
	int		save;
	char	*str;

	size = 1;
	save = i;
	while (save > 9)
	{
		save /= 10;
		size++;
	}
	str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	size--;
	while (i > 9)
	{
		str[size] = (char)((i % 10) + '0');
		i /= 10;
		size--;
	}
	str[0] = i + '0';
	return (str);
}
