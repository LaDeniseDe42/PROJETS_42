/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:04:53 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/22 13:42:49 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*stock;

	stock = malloc(sizeof(t_pile));
	if (!stock)
		return (0);
	init_struct(stock);
	if (argc <= 1)
	{
		free(stock);
		return (1);
	}
	is_digit_sign_or_space(argv, stock);
	if (argv_with_only_space(argv) == 1)
		print_error("il y a un argument vide", stock);
	stock->how_much = how_much_number(argv, argc);
	split_me_this_shit(argv, stock);
	double_not_pass(stock);
	index_me_please(stock);
	lets_the_game_begin(stock);
	free_tab(stock->pile_char_a, stock->pile_char_b);
	free(stock);
	return (0);
}

void	init_struct(t_pile *stock)
{
	stock->pile_char_a = NULL;
	stock->pile_char_b = NULL;
	stock->pile_a1 = NULL;
	stock->pile_b = NULL;
	stock->pile_a = NULL;
	stock->how_much = 0;
}
