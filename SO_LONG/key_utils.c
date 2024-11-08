/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:35:49 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/25 13:24:57 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_sl(t_game *sl)
{
	mlx_close_window(sl->id);
	delete_this_shit(sl);
	print_win("GOOD JOB YOU ARE A TRUE HERO");
}

void	defeat_sl(t_game *sl)
{
	mlx_close_window(sl->id);
	delete_this_shit(sl);
	print_error("YOU FORCE SUBIT A DEFEAT");
}

mlx_image_t	*compt_print(t_game *sl)
{
	int			a;
	const char	*test;
	mlx_image_t	*print_result;

	a = sl->compteur;
	test = ft_itoa(a);
	mlx_delete_image(sl->id, sl->print_result);
	print_result = mlx_put_string(sl->id, test, 60, 40);
	free(((void *)test));
	return (print_result);
}

int	calcullataille(int n)
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
