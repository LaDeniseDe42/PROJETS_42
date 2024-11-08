/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:20:14 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/01 10:39:30 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_img(t_game *sl)
{
	sl->img.hero = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/hero.png");
	sl->img.wall = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/wall.png");
	sl->img.obj = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/collect.png");
	sl->img.ground = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/sol.png");
	sl->img.exit = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/exit.png");
	sl->img.enemy = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/enemy.png");
	sl->img.mag_dead = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/md.png");
	sl->img.heroq = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/hg.png");
	sl->img.herow = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/ha.png");
	sl->img.heroe = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/ha2.png");
	sl->img.mag_cross = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/m.png");
	sl->u = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/u.png");
	sl->mdu = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/mdu.png");
	sl->death = mlx_load_png("/Users/qdenizar/Desktop/so_long/i/death.png");
	if (!(sl->img.hero) || !(sl->img.wall) || !(sl->img.obj) || !(sl->img.exit)
		|| !(sl->img.ground) || !(sl->img.enemy) || (!sl->img.heroq)
		|| (!sl->img.herow) || (!sl->img.heroe) || (!sl->img.mag_dead)
		|| (!sl->img.mag_cross) || (!sl->mdu) || (!sl->u) || (!sl->death))
		print_error3("Seuls les enfants sages ont droit a des images!", sl);
	new_img_finish(sl);
}

void	new_img_finish(t_game *sl)
{
	sl->img.img_mag_dead = mlx_texture_to_image(sl->id, sl->img.mag_dead);
	sl->img.img_hero = mlx_texture_to_image(sl->id, sl->img.hero);
	sl->img.img_wall = mlx_texture_to_image(sl->id, sl->img.wall);
	sl->img.img_collect = mlx_texture_to_image(sl->id, sl->img.obj);
	sl->img.img_ground = mlx_texture_to_image(sl->id, sl->img.ground);
	sl->img.img_exit = mlx_texture_to_image(sl->id, sl->img.exit);
	sl->img.img_enemy = mlx_texture_to_image(sl->id, sl->img.enemy);
	sl->img.img_heroq = mlx_texture_to_image(sl->id, sl->img.heroq);
	sl->img.img_herow = mlx_texture_to_image(sl->id, sl->img.herow);
	sl->img.img_heroe = mlx_texture_to_image(sl->id, sl->img.heroe);
	sl->img_u = mlx_texture_to_image(sl->id, sl->u);
	sl->img_mdu = mlx_texture_to_image(sl->id, sl->mdu);
	sl->img.img_mag_cross = mlx_texture_to_image(sl->id, sl->img.mag_cross);
	sl->img_death = mlx_texture_to_image(sl->id, sl->death);
	if (!(sl->img.img_hero) || !(sl->img.img_wall) || !(sl->img.img_collect)
		|| !(sl->img.img_exit) || !(sl->img.img_ground) || !(sl->img.img_enemy)
		|| !(sl->img.img_mag_dead) || (!sl->img.img_heroq)
		|| (!sl->img.img_herow) || (!sl->img.img_heroe)
		|| (!sl->img.img_mag_cross) || (!sl->img_mdu) || (!sl->img_u)
		|| (!sl->img_death))
		print_error3("Seuls les enfants sages ont droit a des images", sl);
}

void	i_would_like_img_here(t_game *sl)
{
	int	h;
	int	l;

	h = 0;
	while (h < sl->x)
	{
		l = 0;
		while (l < sl->y)
		{
			put_img_on_my_map(sl, l, h);
			l++;
		}
		h++;
	}
}

void	put_img_on_my_map(t_game *sl, int l, int h)
{
	if (sl->total_line[(h * sl->y) + l] == '1')
		mlx_image_to_window(sl->id, sl->img.img_wall, l * 64, h * 64);
	else if (sl->total_line[(h * sl->y) + l] == 'C')
		mlx_image_to_window(sl->id, sl->img.img_collect, l * 64, h * 64);
	else if (sl->total_line[(h * sl->y) + l] == 'E')
		mlx_image_to_window(sl->id, sl->img.img_exit, l * 64, h * 64);
	else if (sl->total_line[(h * sl->y) + l] == 'M')
		mlx_image_to_window(sl->id, sl->img.img_enemy, l * 64, h * 64);
	else if (sl->total_line[(h * sl->y) + l] == 'P')
	{
		mlx_image_to_window(sl->id, sl->img.img_ground, l * 64, h * 64);
		mlx_image_to_window(sl->id, sl->img.img_hero, l * 64, h * 64);
	}
	else if (sl->total_line[(h * sl->y) + l] == 'D')
		mlx_image_to_window(sl->id, sl->img.img_mag_cross, l * 64, h * 64);
	else if (sl->total_line[(h * sl->y) + l] == '0')
		mlx_image_to_window(sl->id, sl->img.img_ground, l * 64, h * 64);
	else
		print_error3("la map contient des caracteres inconnus", sl);
}

void	direction_hero(t_game *sl)
{
	int	l;
	int	h;

	h = 0;
	while (h < sl->x)
	{
		l = 0;
		while (l < sl->y)
		{
			if (sl->total_line[(h * sl->y) + l] == 'P')
			{
				mlx_delete_image(sl->id, sl->img.img_hero);
				sl->img.img_hero = mlx_texture_to_image(sl->id, sl->img.hero);
				mlx_image_to_window(sl->id, sl->img.img_hero, l * 64, h * 64);
				break ;
			}
			l++;
		}
		h++;
	}
}
