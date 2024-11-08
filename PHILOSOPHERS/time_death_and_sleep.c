/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_death_and_sleep.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:19:48 by qdenizar          #+#    #+#             */
/*   Updated: 2023/04/20 14:29:13 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//la fonction renvoie le temps actuel en millisecondes
long long	how_much_time(void)
{
	struct timeval	temps;
	long long		milliseconds;

	gettimeofday(&temps, NULL);
	milliseconds = (temps.tv_sec * 1000) + (temps.tv_usec / 1000);
	return (milliseconds);
}

bool	is_death(long long last_eat, int time_to_die)
{
	if ((((time_to_die) / 1000)) < (how_much_time() - last_eat))
	{
		return (true);
	}
	return (false);
}

void	ft_sleep(int t)
{
	struct timeval	b;
	struct timeval	a;

	gettimeofday(&b, NULL);
	gettimeofday(&a, NULL);
	while (((a.tv_sec - b.tv_sec) * 1000000 + (a.tv_usec - b.tv_usec)) < t)
	{
		usleep(150);
		gettimeofday(&a, NULL);
	}
}
