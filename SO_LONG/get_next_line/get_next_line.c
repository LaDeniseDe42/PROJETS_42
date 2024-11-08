/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:01:30 by qdenizar          #+#    #+#             */
/*   Updated: 2022/12/02 09:36:30 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_zero(char **je_stock_le_buff_de_read)
{
	free(*je_stock_le_buff_de_read);
	*je_stock_le_buff_de_read = 0;
	return (*je_stock_le_buff_de_read);
}

char	*delete_then_save(char *je_stock_le_buff_de_read)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (je_stock_le_buff_de_read[i] && je_stock_le_buff_de_read[i] != '\n')
		i++;
	if (!je_stock_le_buff_de_read[i])
	{
		free_and_zero(&je_stock_le_buff_de_read);
		return (NULL);
	}
	s = ft_calloc(sizeof(char), ft_strlen(je_stock_le_buff_de_read) - i);
	if (!s)
	{
		free_and_zero(&je_stock_le_buff_de_read);
		return (NULL);
	}
	i++;
	c = 0;
	while (je_stock_le_buff_de_read[i])
		s[c++] = je_stock_le_buff_de_read[i++];
	free_and_zero(&je_stock_le_buff_de_read);
	return (s);
}

char	*buff_me_whith_read(int fd, char *je_stock_le_buff_de_read)
{
	char		*buff_de_read;
	ssize_t		value_of_read;

	value_of_read = 1;
	buff_de_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff_de_read)
		return (NULL);
	while (value_of_read > 0 && !ft_strchr(je_stock_le_buff_de_read, '\n'))
	{
		value_of_read = read(fd, buff_de_read, BUFFER_SIZE);
		if (value_of_read == -1)
		{
			free_and_zero(&je_stock_le_buff_de_read);
			free(buff_de_read);
			return (NULL);
		}
		buff_de_read[value_of_read] = '\0';
		je_stock_le_buff_de_read = ft_strjoin(je_stock_le_buff_de_read,
				buff_de_read);
	}
	free(buff_de_read);
	return (je_stock_le_buff_de_read);
}

char	*give_me_the_line(char *je_stock_le_buff_de_read)
{
	int		i;
	char	*line;

	i = 0;
	if (!je_stock_le_buff_de_read[i])
		return (NULL);
	while (je_stock_le_buff_de_read[i] && je_stock_le_buff_de_read[i] != '\n')
		i++;
	if (je_stock_le_buff_de_read[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (je_stock_le_buff_de_read[++i] && je_stock_le_buff_de_read[i] != '\n')
		line[i] = je_stock_le_buff_de_read[i];
	if (je_stock_le_buff_de_read[i] == '\n')
		line[i] = je_stock_le_buff_de_read[i];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*je_stock_le_buff_de_read;
	char		*the_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	je_stock_le_buff_de_read = buff_me_whith_read(fd, je_stock_le_buff_de_read);
	if (!je_stock_le_buff_de_read)
		return (NULL);
	the_line = give_me_the_line(je_stock_le_buff_de_read);
	je_stock_le_buff_de_read = delete_then_save(je_stock_le_buff_de_read);
	return (the_line);
}
