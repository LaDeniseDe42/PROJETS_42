/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharandco.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:46:28 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/25 09:41:17 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char caractere, int *evolution)
{
	if ((write(1, &caractere, 1) == -1))
		return (-1);
	*evolution += 1;
	return (*evolution);
}

int	ft_putstr(const char *str, int *evolution)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		if (ft_putchar(*str, evolution) == -1)
			return (-1);
		++str;
		i++;
	}
	return (*evolution);
}

int	print_pointeur(unsigned long int n, int *evolution)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ft_putnbr_hexa_f(n, evolution) == -1)
		return (-1);
	*evolution += 2;
	return (0);
}
