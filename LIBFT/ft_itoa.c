/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:38:50 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/10 16:41:17 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcullataille(int n)
{
	int	taille;

	taille = 0;
	if (n <= 0)
		taille++;
	while (n != 0)
	{
		taille++;
		n = n / 10;
	}
	return (taille);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				i;
	unsigned int	un;

	if (n < 0)
		un = -n;
	else
		un = n;
	i = calcullataille(n);
	result = (char *)ft_calloc((calcullataille(n) + 1), sizeof(char));
	if (!result)
		return (0);
	i--;
	if (n == 0)
		result[0] = '0';
	while (un > 0)
	{
		result[i--] = 48 + (un % 10);
		un = un / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
