/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:36:16 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/25 14:47:19 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_event(void *sl)
{
	if (mlx_is_key_down(((t_game *) sl)->id, MLX_KEY_SPACE))
		i_would_explosion_here(sl);
	else if (mlx_is_key_down(((t_game *) sl)->id, MLX_KEY_F))
		i_would_danse(sl);
	else if (mlx_is_key_down(((t_game *) sl)->id, MLX_KEY_R))
		i_would_like_provocation_here(sl);
	else if (mlx_is_key_down(((t_game *) sl)->id, MLX_KEY_M))
		i_would_death(sl);
}

void	sl_init(t_game *sl, char *map)
{
	read_map(map, sl);
	map_is_ok(sl, map);
	sl->id = mlx_init(sl->y * 64, sl->x * 64, "HEROES", true);
	if (!sl->id)
		print_error2("A bird break the window", sl);
	new_img(sl);
	i_would_like_img_here(sl);
	sl->print_result = mlx_put_string(sl->id, "0", 60, 40);
}

int	main(int argc, char **argv)
{
	t_game	sl;

	if (argc != 2)
		print_error("Ya comme un petit probleme d'arguments ici.\n");
	sl.compt_collect = 0;
	sl_init(&sl, argv[1]);
	mlx_key_hook(sl.id, &hook, &sl);
	mlx_loop_hook(sl.id, &loop_event, &sl.id);
	mlx_loop(sl.id);
	echap(&sl);
	return (0);
}
