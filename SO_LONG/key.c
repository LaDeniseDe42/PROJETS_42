/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:20:55 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/24 16:38:39 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(mlx_key_data_t keydata, void *param)
{
	t_game	*sl;

	sl = param;
	(void)keydata;
	if (mlx_is_key_down(sl->id, MLX_KEY_ESCAPE))
		echap(sl);
	else if (mlx_is_key_down(sl->id, MLX_KEY_W))
		move_w(sl);
	else if (mlx_is_key_down(sl->id, MLX_KEY_S))
		move_s(sl);
	else if (mlx_is_key_down(sl->id, MLX_KEY_A))
		move_a(sl);
	else if (mlx_is_key_down(sl->id, MLX_KEY_D))
		move_d(sl);
}

void	move_w(t_game *sl)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen_sl(sl->total_line))
	{
		if (sl->total_line[i] == 'P')
			break ;
	}
	if (sl->total_line[i - sl->y] == 'C')
		chest_w(sl, i);
	if (sl->total_line[i - sl->y] == 'M')
		defeat_sl(sl);
	if (sl->total_line[i - sl->y] == 'E' && sl->nb_collect == sl->compt_collect)
		win_sl(sl);
	else if (sl->total_line[i - sl->y] != '1' && sl->total_line[i
			- sl->y] != 'E')
	{
		sl->total_line[i] = '0';
		sl->total_line[i - sl->y] = 'P';
		sl->compteur += 1;
		ft_printf("%d\n", sl->compteur);
		direction_hero(sl);
		sl->print_result = compt_print(sl);
	}
}

void	move_s(t_game *sl)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen_sl(sl->total_line))
	{
		if (sl->total_line[i] == 'P')
			break ;
	}
	if (sl->total_line[i + sl->y] == 'C')
		chest_s(sl, i);
	if (sl->total_line[i + sl->y] == 'M')
		defeat_sl(sl);
	if (sl->total_line[i + sl->y] == 'E' && sl->nb_collect == sl->compt_collect)
		win_sl(sl);
	else if (sl->total_line[i + sl->y] != '1' && sl->total_line[i
			+ sl->y] != 'E')
	{
		sl->total_line[i] = '0';
		sl->total_line[i + sl->y] = 'P';
		sl->compteur += 1;
		ft_printf("%d\n", sl->compteur);
		direction_hero(sl);
		sl->print_result = compt_print(sl);
	}
}

void	move_a(t_game *sl)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen_sl(sl->total_line))
	{
		if (sl->total_line[i] == 'P')
			break ;
	}
	if (sl->total_line[i - 1] == 'C')
		chest_a(sl, i);
	if (sl->total_line[i - 1] == 'M')
		defeat_sl(sl);
	if (sl->total_line[i - 1] == 'E' && sl->nb_collect == sl->compt_collect)
		win_sl(sl);
	else if (sl->total_line[i - 1] != '1' && sl->total_line[i
			- 1] != 'E')
	{
		sl->total_line[i] = '0';
		sl->total_line[i - 1] = 'P';
		sl->compteur += 1;
		ft_printf("%d\n", sl->compteur);
		direction_hero(sl);
		sl->print_result = compt_print(sl);
	}
}

void	move_d(t_game *sl)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen_sl(sl->total_line))
	{
		if (sl->total_line[i] == 'P')
			break ;
	}
	if (sl->total_line[i + 1] == 'C')
		chest_d(sl, i);
	if (sl->total_line[i + 1] == 'M')
		defeat_sl(sl);
	if (sl->total_line[i + 1] == 'E' && sl->nb_collect == sl->compt_collect)
		win_sl(sl);
	else if (sl->total_line[i + 1] != '1' && sl->total_line[i
			+ 1] != 'E')
	{
		sl->total_line[i] = '0';
		sl->total_line[i + 1] = 'P';
		sl->compteur += 1;
		ft_printf("%d\n", sl->compteur);
		direction_hero(sl);
		sl->print_result = compt_print(sl);
	}
}
