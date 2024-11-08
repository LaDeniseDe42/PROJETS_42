/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changelabase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:00:34 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/25 09:38:37 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_min(unsigned int n, int *evolution)
{
	int		a;
	char	*bminus;

	bminus = "0123456789abcdef";
	a = n % 16;
	if (n >= 16)
	{
		if (ft_putnbr_hexa_min(n / 16, evolution) == -1)
			return (-1);
		a = n % 16;
		n = n / 16;
	}
	if (ft_putchar(bminus[a], evolution) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_hexa_maj(unsigned int n, int *evolution)
{
	int		a;
	char	*bminus;

	bminus = "0123456789ABCDEF";
	a = n % 16;
	if (n >= 16)
	{
		if (ft_putnbr_hexa_maj(n / 16, evolution) == -1)
			return (-1);
		a = n % 16;
		n = n / 16;
	}
	if (ft_putchar(bminus[a], evolution) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_deci(int n, int *evolution)
{
	long int	nbl;

	nbl = n;
	if (nbl < 0)
	{
		if (ft_putchar('-', evolution) == -1)
			return (-1);
		nbl = nbl * -1;
	}
	if (nbl > 9)
	{
		if (ft_putnbr_deci(nbl / 10, evolution) == -1)
			return (-1);
		if (ft_putnbr_deci(nbl % 10, evolution) == -1)
			return (-1);
	}
	else
		if (ft_putchar(nbl + '0', evolution) == -1)
			return (-1);
	return (0);
}

int	ft_putnbr_hexa_f(unsigned long int n, int *evolution)
{
	int		a;
	char	*bminus;

	bminus = "0123456789abcdef";
	a = n % 16;
	if (n >= 16)
	{
		if (ft_putnbr_hexa_f(n / 16, evolution) == -1)
			return (-1);
		a = n % 16;
		n = n / 16;
	}
	if (ft_putchar(bminus[a], evolution) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_deci_unsigned(unsigned int n, int *evolution)
{
	unsigned int	nbl;
	int				moinsun;

	nbl = n;
	moinsun = 0;
	if (nbl < 0)
	{
		if (ft_putchar('-', evolution) == -1)
			return (-1);
		nbl = nbl * -1;
	}
	if (nbl > 9)
	{
		if (ft_putnbr_deci_unsigned(nbl / 10, evolution) == -1)
			return (-1);
		if (ft_putnbr_deci_unsigned(nbl % 10, evolution) == -1)
			return (-1);
	}
	else
		if (ft_putchar(nbl + '0', evolution) == -1)
			return (-1);
	return (0);
}
