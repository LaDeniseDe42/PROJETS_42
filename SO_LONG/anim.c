/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:10:02 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/17 09:47:54 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	i_would_danse(t_game *sl)
{
	int			h;
	int			l;
	static int	i = 0;

	h = find_hero_h(sl);
	l = find_hero_l(sl);
	if (i == 0)
	{
		mlx_image_to_window(sl->id, sl->img.img_heroq, l * 64, h * 64);
		i++;
	}
	else if (i == 1)
	{
		usleep(230000);
		mlx_delete_image(sl->id, sl->img.img_heroq);
		sl->img.img_heroq = mlx_texture_to_image(sl->id, sl->img.heroq);
		mlx_image_to_window(sl->id, sl->img.img_hero, l * 64, h * 64);
		i--;
	}
}

void	i_would_death(t_game *sl)
{
	int			h;
	int			l;
	static int	i = 0;

	h = find_hero_h(sl);
	l = find_hero_l(sl);
	if (i == 0)
	{
		mlx_image_to_window(sl->id, sl->img_death, (h / sl->x), (l / sl->y));
		i++;
	}
	else if (i == 1)
	{
		usleep(230000);
		mlx_delete_image(sl->id, sl->img_death);
		sl->img_death = mlx_texture_to_image(sl->id, sl->death);
		i--;
	}
}

void	i_would_explosion_here(t_game *sl)
{
	int			h;
	int			l;
	static int	i = 0;

	h = find_hero_h(sl);
	l = find_hero_l(sl);
	if (i == 0)
	{
		put_anim_on_my_map(sl, l, h);
		i++;
	}
	else
	{
		usleep(230000);
		i_would_like_img_here(sl);
		i--;
	}
}

void	put_anim_on_my_map(t_game *sl, int l, int h)
{
	if (sl->total_line[(h * sl->y) + (l - 1)] == 'M')
	{
		sl->total_line[(h * sl->y) + (l - 1)] = 'D';
		mlx_image_to_window(sl->id, sl->img.img_mag_dead, (l - 1) * 64, h * 64);
	}
	else if (sl->total_line[(h * sl->y) + (l + 1)] == 'M')
	{
		sl->total_line[(h * sl->y) + (l + 1)] = 'D';
		mlx_image_to_window(sl->id, sl->img.img_mag_dead, (l + 1) * 64, h * 64);
	}
	else if (sl->total_line[((h - 1) * sl->y) + l] == 'M')
	{
		sl->total_line[(h - 1) * sl->y + l] = 'D';
		mlx_image_to_window(sl->id, sl->img.img_mag_dead, l * 64, (h - 1) * 64);
	}
	else if (sl->total_line[((h + 1) * sl->y) + l] == 'M')
	{
		sl->total_line[((h + 1) * sl->y) + l] = 'D';
		mlx_image_to_window(sl->id, sl->img.img_mag_dead, l * 64, (h + 1) * 64);
	}
}

void	i_would_like_provocation_here(t_game *sl)
{
	int			h;
	int			l;
	static int	i = 0;

	h = find_hero_h(sl);
	l = find_hero_l(sl);
	if (i == 0)
	{
		provocation(sl, l, h);
		i++;
	}
	else if (i == 1)
	{
		usleep(230000);
		i--;
	}
}
