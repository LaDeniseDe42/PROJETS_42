/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:29:08 by qdenizar          #+#    #+#             */
/*   Updated: 2023/04/04 14:18:33 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pointeur;
	size_t			i;

	pointeur = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		*pointeur = '\0';
		pointeur++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		return (0);
	if (mem)
		ft_bzero(mem, count * size);
	return (mem);
}

void	free_and_stop(struct s_philo *philo)
{
	int	i;

	i = 1;
	while (i < philo->rules->nb_philo)
	{
		pthread_mutex_destroy(philo->fork);
		i++;
	}
	free(philo->fork);
	free(philo);
}

void	print_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}
