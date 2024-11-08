/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:14:34 by qdenizar          #+#    #+#             */
/*   Updated: 2023/03/20 13:22:16 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "pipex.h"
# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

typedef struct son
{
	int		fd;
	int		fd2;
	int		henry;
	int		i;
	char	**total_path;
	char	**split_cmd1_for_my_son;
	char	*cmd_slash;
	char	*cmd_path;
	int		odile;
	char	**split_cm2_for_my_second_son;
	int		cmd;
}			t_my_child;

int		ft_strlen(char *string);
void	print_error_f(char *message, char **argv);
void	print_error_c2(char *message, char **argv);
void	print_error_c(char *message, char **argv);
void	print_error(char *message);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*free_tab(char **tab);
void	free_henry(t_my_child child);
void	free_odile(t_my_child child);

void	init_my_child(t_my_child *henry_and_odile);
void	go_work_henry(t_my_child henry_and_odile, char **a, char **e, int *p);
void	help_henry(t_my_child *child, int *p);
void	odile_quest(t_my_child child, char **a, char **e, int *p);
void	go_work_odile(t_my_child henry_and_odile, char **a, char **e, int *p);
void	help_odile(t_my_child *child, int *p);
int		verif_cmd(char **argv);
void	scratch_lines_henry(t_my_child child, char **e);
void	scratch_lines_odile(t_my_child child, char **e);

#endif