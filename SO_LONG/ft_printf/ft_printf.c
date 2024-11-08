/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:01 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/17 10:14:53 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	de_quel_type(const char *pokeball, va_list list, int salameche,
		int *evolution)
{
	int	r;

	r = 0;
	if (pokeball[salameche] == 'c')
		r = ft_putchar(va_arg(list, int), evolution);
	else if (pokeball[salameche] == 's')
		r = ft_putstr(va_arg(list, char *), evolution);
	else if (pokeball[salameche] == 'p')
		r = print_pointeur(va_arg(list, unsigned long int), evolution);
	else if (pokeball[salameche] == 'd' || pokeball[salameche] == 'i')
		r = ft_putnbr_deci(va_arg(list, int), evolution);
	else if (pokeball[salameche] == 'u')
		r = ft_putnbr_deci_unsigned(va_arg(list, unsigned int),
				evolution);
	else if (pokeball[salameche] == 'x')
		r = ft_putnbr_hexa_min(va_arg(list, unsigned int), evolution);
	else if (pokeball[salameche] == 'X')
		r = ft_putnbr_hexa_maj(va_arg(list, unsigned int), evolution);
	else if (pokeball[salameche] == '%')
		r = ft_putchar('%', evolution);
	return (r);
}

int	ft_printf(const char *pokeball, ...)
{
	int			salameche;
	int			*evolution;
	int			nb;
	va_list		list;

	salameche = 0;
	nb = 0;
	evolution = &nb;
	va_start(list, pokeball);
	if (!pokeball)
		return (-1);
	while (pokeball[salameche])
	{
		if (pokeball[salameche] == '%')
		{
			salameche++;
			if (de_quel_type(pokeball, list, salameche, evolution) == -1)
				return (-1);
		}
		else if (ft_putchar(pokeball[salameche], evolution) == -1)
			return (-1);
		salameche++;
	}
	va_end(list);
	return (*evolution);
}
