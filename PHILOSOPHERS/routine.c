/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:11:50 by qdenizar          #+#    #+#             */
/*   Updated: 2023/04/24 14:46:42 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_eat_eat(t_un_philo	*p)
{
	pthread_mutex_lock(&(p->fork[(p->id)]));
	print_script(how_much_time() - p->rules->milli_s, p->id,
		"has taken a fork\n", &p->rules->msg);
	pthread_mutex_lock(&(p->fork[(p->id + 1) % p->rules->nb_philo]));
	print_script(how_much_time() - p->rules->milli_s, p->id,
		"has taken a fork\n", &p->rules->msg);
	p->last_eat = how_much_time();
	p->is_eating = 1;
	print_script(how_much_time() - p->rules->milli_s, p->id, "is eating\n",
		&p->rules->msg);
	ft_sleep(p->rules->time_to_eat);
	p->eated++;
	pthread_mutex_unlock(&(p->fork[(p->id + 1) % p->rules->nb_philo]));
	pthread_mutex_unlock(&(p->fork[(p->id)]));
	p->is_eating = 0;
}

void	reduce_lines(struct s_philo *philo, struct s_rules rules, int i)
{
	pthread_mutex_lock(&(philo->rules->msg));
	print_script(how_much_time() - rules.milli_s, philo[i].id, "died\n",
		&rules.msg);
	free_and_stop(philo);
}
