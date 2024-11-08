/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:38:19 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/25 09:42:35 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int				ft_putnbr_hexa_min(unsigned int n, int *evolution);
int				ft_putchar(const char caractere, int *evolution);
int				ft_printf(const char *pokeball, ...);
int				ft_putstr(const char *str, int *evolution);
int				ft_putnbr_hexa_maj(unsigned int n, int *evolution);
int				ft_putnbr_deci(int n, int *evolution);
int				de_quel_type(const char *pokeball, va_list list,
					int salameche, int *evolution);
int				ft_putnbr_hexa_f(unsigned long int n, int *evolution);
int				ft_putnbr_deci_unsigned(unsigned int n, int *evolution);
int				print_pointeur(unsigned long int n, int *evolution);

#endif