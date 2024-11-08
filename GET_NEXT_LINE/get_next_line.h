/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:07:34 by qdenizar          #+#    #+#             */
/*   Updated: 2022/12/02 10:02:04 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*delete_then_save(char *je_stock_le_buff_de_read);
char	*give_me_the_line(char *je_stock_le_buff_de_read);
char	*buff_me_whith_read(int fd, char *je_stock_le_buff_de_read);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*free_and_zero(char **je_stock_le_buff_de_read);

#endif