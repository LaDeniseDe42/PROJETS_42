/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:46:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/11 14:13:47 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chest_w(t_game *sl, int i)
{
	sl->compt_collect++;
	sl->total_line[i - sl->y] = '0';
	i_would_like_img_here(sl);
}

void	chest_a(t_game *sl, int i)
{
	sl->compt_collect++;
	sl->total_line[i - 1] = '0';
	i_would_like_img_here(sl);
}

void	chest_s(t_game *sl, int i)
{
	sl->compt_collect++;
	sl->total_line[i + sl->y] = '0';
	i_would_like_img_here(sl);
}

void	chest_d(t_game *sl, int i)
{
	sl->compt_collect++;
	sl->total_line[i + 1] = '0';
	i_would_like_img_here(sl);
}
