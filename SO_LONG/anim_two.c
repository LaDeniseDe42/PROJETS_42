/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:16:22 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/13 14:50:51 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_hero_l(t_game *sl)
{
	int	h;
	int	l;

	h = 0;
	while (h < sl->x)
	{
		l = 0;
		while (l < sl->y)
		{
			if (sl->total_line[(h * sl->y) + l] == 'P')
				break ;
			l++;
		}
		if (sl->total_line[(h * sl->y) + l] == 'P')
			break ;
		h++;
	}
	return (l);
}

int	find_hero_h(t_game *sl)
{
	int	h;
	int	l;

	h = 0;
	while (h < sl->x)
	{
		l = 0;
		while (l < sl->y)
		{
			if (sl->total_line[(h * sl->y) + l] == 'P')
				break ;
			l++;
		}
		if (sl->total_line[(h * sl->y) + l] == 'P')
			break ;
		h++;
	}
	return (h);
}

void	provocation(t_game *sl, int l, int h)
{
	if (sl->total_line[(h * sl->y) + (l - 1)] == 'M')
	{
		sl->total_line[(h * sl->y) + (l - 1)] = 'D';
		mlx_image_to_window(sl->id, sl->img_mdu, (l - 1) * 64, h * 64);
	}
	if (sl->total_line[(h * sl->y) + (l + 1)] == 'M')
	{
		sl->total_line[(h * sl->y) + (l + 1)] = 'D';
		mlx_image_to_window(sl->id, sl->img_mdu, (l + 1) * 64, h * 64);
	}
	if (sl->total_line[((h - 1) * sl->y) + l] == 'M')
	{
		sl->total_line[(h - 1) * sl->y + l] = 'D';
		mlx_image_to_window(sl->id, sl->img_mdu, l * 64, (h - 1) * 64);
	}
	if (sl->total_line[((h + 1) * sl->y) + l] == 'M')
	{
		sl->total_line[((h + 1) * sl->y) + l] = 'D';
		mlx_image_to_window(sl->id, sl->img_mdu, l * 64, (h + 1) * 64);
	}
	provocation_two(sl, l, h);
}

void	provocation_two(t_game *sl, int l, int h)
{
	if (sl->total_line[(h * sl->y) + (l - 1)] == '1'
		|| sl->total_line[((h + 1) * sl->y) + l] == '0')
		mlx_image_to_window(sl->id, sl->img_u, (l - 1) * 64, h * 64);
	if (sl->total_line[(h * sl->y) + (l + 1)] == '1'
		|| sl->total_line[((h + 1) * sl->y) + l] == '0')
		mlx_image_to_window(sl->id, sl->img_u, (l + 1) * 64, h * 64);
	if (sl->total_line[((h - 1) * sl->y) + l] == '1'
		|| sl->total_line[((h + 1) * sl->y) + l] == '0')
		mlx_image_to_window(sl->id, sl->img_u, l * 64, (h - 1) * 64);
	if (sl->total_line[((h + 1) * sl->y) + l] == '1'
		|| sl->total_line[((h + 1) * sl->y) + l] == '0')
		mlx_image_to_window(sl->id, sl->img_u, l * 64, (h + 1) * 64);
}
