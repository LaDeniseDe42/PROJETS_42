/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:30:39 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/25 13:39:06 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *path, t_game *sl)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		print_error("Je refuse d'ouvrir une map aussi nulle\n");
	map_is_completly_ok(path);
	line = get_next_line(fd);
	sl->x = 0;
	sl->y = ft_strlen_sl(line) - 1;
	sl->total_line = ft_strdup(line);
	sl->compteur = 0.0;
	free(line);
	while (line)
	{
		sl->x++;
		line = get_next_line(fd);
		if (line)
			sl->total_line = ft_strjoin_sl(sl->total_line, line);
	}
	close(fd);
}

void	map_is_ok(t_game *sl, char *map)
{
	if (sl->x * sl->y != ft_strlen_sl(sl->total_line))
		print_error2("Have you read the subject? Map must be rectangular", sl);
	wall_is_ok(sl);
	map_chek_config(sl);
	flood_fill(sl);
	free(sl->total_line);
	read_map(map, sl);
}

void	map_chek_config(t_game *sl)
{
	int	i;
	int	e;
	int	p;

	e = 0;
	p = 0;
	i = 0;
	sl->nb_collect = 0;
	while (i < ft_strlen_sl(sl->total_line))
	{
		if (sl->total_line[i] == 'E')
			e++;
		else if (sl->total_line[i] == 'C')
			sl->nb_collect++;
		else if (sl->total_line[i] == 'P')
			p++;
		i++;
	}
	if (e == 0 || e > 1)
		print_error2("La Map doit avoir une seule entree", sl);
	if (sl->nb_collect == 0)
		print_error2("Il doit y avoir au minimun un collectible", sl);
	if (p == 0 || p > 1)
		print_error2("La map doit avoir un point de depart", sl);
}

void	wall_is_ok(t_game *sl)
{
	int	i;

	i = 0;
	while (i < ft_strlen_sl(sl->total_line))
	{
		if (i < sl->y)
		{
			if (sl->total_line[i] != '1')
				print_error2("WHAT THE FUCK HAPPENS WHIT MY WALLS???", sl);
		}
		else if (i % sl->y == 0 || i % sl->y == sl->y - 1)
		{
			if (sl->total_line[i] != '1')
				print_error2("WHAT THE FUCK HAPPENS WHIT MY WALLS???", sl);
		}
		else if (i > ft_strlen_sl(sl->total_line) - sl->y)
		{
			if (sl->total_line[i] != '1')
				print_error2("WHAT THE FUCK HAPPENS WHIT MY WALLS???", sl);
		}
		i++;
	}
}

void	map_is_completly_ok(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if ((map[i - 1] != 'r') || (map[i - 2] != 'e')
		|| (map[i - 3] != 'b') || (map[i - 4] != '.'))
		print_error("ceci n'est pas une map\n");
}
