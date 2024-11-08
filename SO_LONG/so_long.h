/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:11:10 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/25 13:26:32 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/qdenizar/goinfre/MLX42/MLX42/include/MLX42/MLX42.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_image
{
	mlx_texture_t	*hero;
	mlx_texture_t	*heroq;
	mlx_texture_t	*herow;
	mlx_texture_t	*heroe;
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*obj;
	mlx_texture_t	*exit;
	mlx_texture_t	*enemy;
	mlx_texture_t	*mag_dead;
	mlx_texture_t	*mag_cross;
	mlx_image_t		*img_mag_cross;
	mlx_image_t		*img_heroq;
	mlx_image_t		*img_herow;
	mlx_image_t		*img_heroe;
	mlx_image_t		*img_mag_dead;
	mlx_image_t		*img_enemy;
	mlx_image_t		*img_hero;
	mlx_image_t		*img_ground;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_exit;
	char			**ani;
}					t_image;

typedef struct s_game
{
	mlx_t			*id;
	int32_t			x;
	int32_t			y;
	int				compteur;
	char			*total_line;
	int				compt_collect;
	int				nb_collect;
	t_image			img;
	mlx_image_t		*print_result;
	mlx_texture_t	*mdu;
	mlx_texture_t	*u;
	mlx_image_t		*img_mdu;
	mlx_image_t		*img_u;
	mlx_texture_t	*death;
	mlx_image_t		*img_death;
	char			*start_hero;
}					t_game;

void				hook(mlx_key_data_t keydata, void *param);
char				*ft_strdup(const char *s1);
void				read_map(char *path, t_game *sl);
char				*ft_strjoin_sl(char *s1, char *s2);
int					ft_strlcpy(char *dst, char *src, int dstsize);
void				print_error(char *message);
void				wall_is_ok(t_game *sl);
void				map_is_ok(t_game *sl, char *map);
void				map_is_completly_ok(char *map);
void				map_chek_config(t_game *sl);
void				i_would_danse(t_game *sl);
void				i_would_explosion_here(t_game *sl);
void				i_would_like_img_here(t_game *sl);
void				chest_w(t_game *sl, int i);
void				chest_a(t_game *sl, int i);
void				chest_s(t_game *sl, int i);
void				chest_d(t_game *sl, int i);
void				put_img_on_my_map(t_game *sl, int h, int l);
void				new_img(t_game *sl);
void				new_img_finish(t_game *sl);
int					ft_strlen_sl(char *s);
void				move_w(t_game *sl);
void				move_a(t_game *sl);
void				move_s(t_game *sl);
void				move_d(t_game *sl);
void				win_sl(t_game *sl);
void				defeat_sl(t_game *sl);
void				flood_fill(t_game *sl);
int					flood(int x, char *total_line, t_game *slb);
char				*ft_itoa(int n);
int					calcullataille(int n);
mlx_image_t			*compt_print(t_game *sl);
void				move_my_hero(t_game *sl, int i);
void				direction_hero(t_game *sl);
void				take_collect(t_game *sl);
void				dance_for_me(t_game *sl);
void				put_anim_on_my_map(t_game *sl, int l, int h);
void				i_would_like_animation_here(t_game *sl);
void				provocation(t_game *sl, int l, int h);
void				i_would_like_provocation_here(t_game *sl);
void				provocation_two(t_game *sl, int l, int h);
void				loop_event(void *sl);
int					find_hero_h(t_game *sl);
int					find_hero_l(t_game *sl);
void				i_would_danse_two(t_game *sl);
void				i_would_death(t_game *sl);
void				delete_this_shit(t_game *sl);
void				finish_me(t_game *sl);
void				echap(t_game *sl);
void				print_win(char *message);
void				print_error3(char *message, t_game *sl);
void				print_error2(char *message, t_game *sl);
#endif
