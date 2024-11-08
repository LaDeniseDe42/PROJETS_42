/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:28:12 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/25 13:28:06 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood(int x, char *total_line, t_game *slb)
{
	static int	i = 0;

	if ((x < slb->y) || (x > ft_strlen_sl(total_line) - slb->y) || ((x
				% slb->y) == 0) || ((x % slb->y) == slb->y - 1)
		|| (total_line[x] == '1'))
		return (0);
	if (total_line[x] == 'C' || total_line[x] == 'E')
		i++;
	total_line[x] = '1';
	flood(x + 1, total_line, slb);
	flood(x - 1, total_line, slb);
	flood(x + slb->y, total_line, slb);
	flood(x - slb->y, total_line, slb);
	return (i);
}

void	flood_fill(t_game *sl)
{
	int		i;
	int		collected;
	t_game	*slb;

	slb = sl;
	i = 0;
	while (i++ < ft_strlen_sl(slb->total_line))
	{
		if (slb->total_line[i] == 'P')
			break ;
	}
	collected = flood((i), slb->total_line, slb);
	if (collected != slb->nb_collect + 1)
	{
		print_error2("une eruption empeche votre hero de partir en mission",
			sl);
	}
}
