/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:55:38 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/01 10:40:50 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_this_shit(t_game *sl)
{
	mlx_delete_texture(sl->img.hero);
	mlx_delete_texture(sl->img.heroq);
	mlx_delete_texture(sl->img.herow);
	mlx_delete_texture(sl->img.heroe);
	mlx_delete_texture(sl->img.ground);
	mlx_delete_texture(sl->img.obj);
	mlx_delete_texture(sl->img.wall);
	mlx_delete_texture(sl->img.exit);
	mlx_delete_texture(sl->img.enemy);
	mlx_delete_texture(sl->img.mag_cross);
	mlx_delete_texture(sl->img.mag_dead);
	mlx_delete_texture(sl->mdu);
	mlx_delete_texture(sl->death);
	mlx_delete_texture(sl->u);
	free(sl->total_line);
	sl->total_line = NULL;
}

void	finish_me(t_game *sl)
{
	mlx_terminate(sl->id);
}

void	echap(t_game *sl)
{
	mlx_close_window(sl->id);
	delete_this_shit(sl);
	print_error("PLEUTRE, COUARD, LACHE");
}
