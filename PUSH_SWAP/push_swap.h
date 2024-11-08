/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:30:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/02/22 10:16:41 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_p
{
	char			**pile_char_a;
	char			**pile_char_b;
	int				*pile_a1;
	int				*pile_a;
	int				*pile_b;
	int				how_much;
}					t_pile;

typedef struct t_la_pour_gratter_deux_ligne
{
	int	i;
	int	j;
	int	how_much;
}		t_la_pour_gratter_deux_ligne;

void	print_error(char *message, t_pile *stock);
void	print_error2(t_pile *stock, char **buff2);
void	print_error3(char *message, t_pile *stock, char **tab);
void	free_tab(char **tab, char **tab2);
void	free_my_big_tab_of_int_stars(int *tab, int *tab2, int *tab3);

int		ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(char *str, t_pile *stock, char **tab);
char	**ft_split(char const *s, char c);
char	*ft_workforme(char const *s, char c, int i);
int		ft_nbc(char const *s, char separateur);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(char *s, int c);

void	is_digit_sign_or_space(char **argv, t_pile *stock);
int		how_much_number(char **argv, int argc);
int		argv_with_only_space(char **argv);
int		read_my_back(char **argv, int i, int j);
int		how_much_number_two(char **argv, int i, int j);
int		ft_isdigit(char c);
void	init_struct(t_pile *stock);
void	stock_me_this_shit(char **bufarg, t_pile *stock);
void	split_me_this_shit(char **argv, t_pile *stock);
void	double_not_pass(t_pile *stock);
void	index_me_please(t_pile *stock);

void	lets_the_game_begin(t_pile *stock);
int		ft_isdigit_exept_0_a(t_pile *stock, int i);
int		ft_isdigit_exept_0_b(t_pile *stock, int i);
int		nb_of_nb_b(t_pile *stock);
int		nb_of_nb_a(t_pile *stock);
void	i_hope_this_isnt_already_sort(t_pile *stock);

void	sa(t_pile *stock);
void	sb(t_pile *stock);
void	ss(t_pile *stock);
void	pb(t_pile *stock);
void	pa(t_pile *stock);
void	ra(t_pile *stock);
void	rb(t_pile *stock);
void	rr(t_pile *stock);
void	rra(t_pile *stock);
void	rrb(t_pile *stock);
void	rrr(t_pile *stock);
void	rrr(t_pile *stock);

void	move_one_up_a(t_pile *stock);
void	move_one_up_b(t_pile *stock);
void	move_one_down_b(t_pile *stock);
void	move_one_down_a(t_pile *stock);
void	sort_3_numbers(t_pile *stock);
void	sort_3_numbers_bis(t_pile *stock);
void	sort_4_or_5_numbers(t_pile *stock);
void	sort_more_and_more(t_pile *stock);
void	do_the_while_of_sort(t_pile *stock, int i, int j, int len);
void	do_the_while_of_sort2(t_pile *stock, int i, int j, int len);

#endif