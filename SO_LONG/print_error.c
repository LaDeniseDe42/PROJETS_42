/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:43:22 by qdenizar          #+#    #+#             */
/*   Updated: 2023/01/25 14:53:14 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_win(char *message)
{
	write(1, message, ft_strlen(message));
	exit(1);
}

void	print_error2(char *message, t_game *sl)
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	free(sl->total_line);
	sl->total_line = NULL;
	exit(1);
}

void	print_error3(char *message, t_game *sl)
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	mlx_close_window(sl->id);
	delete_this_shit(sl);
	exit(1);
}

void	print_error(char *message)
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	exit(1);
}
