/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:54:42 by qdenizar          #+#    #+#             */
/*   Updated: 2023/04/25 15:16:47 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *arg)
{
	t_un_philo	*p;

	p = arg;
	while (1)
	{
		eat_eat_eat(p);
		print_script(how_much_time() - p->rules->milli_s, p->id, "is sleeping\n",
			&p->rules->msg);
		ft_sleep(p->rules->time_to_sleep);
		print_script(how_much_time() - p->rules->milli_s, p->id,
			"is thinking\n", &p->rules->msg);
	}
	return (0);
}

static bool	philo_init(t_rules *rules, t_un_philo *philo, pthread_mutex_t *fork)
{
	int			i;
	pthread_t	thread;

	i = 0;
	while (i < rules->nb_philo)
	{
		philo[i].id = i;
		philo[i].eated = 0;
		philo[i].fork = fork;
		philo[i].rules = rules;
		philo[i].last_eat = rules->milli_s;
		philo[i].platon = thread;
		philo[i].is_eating = 0;
		pthread_create(&thread, NULL, &start_routine, &(philo[i]));
		i++;
		usleep(100);
	}
	i = 0;
	return (true);
}

static int	forks_init(pthread_mutex_t *forks, int philo_nbr)
{
	while (philo_nbr > 0)
	{
		if (pthread_mutex_init(&(forks[philo_nbr - 1]), NULL) != 0)
			return (0);
		philo_nbr--;
	}
	return (1);
}

static bool	rules_init(t_rules *rules, char **argv, int i)
{
	int	num;

	rules->milli_s = how_much_time();
	if (pthread_mutex_init(&rules->msg, NULL) != 0)
		return (1);
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num == 0)
			return (false);
		if (i == 1)
			rules->nb_philo = num;
		else if (i == 2)
			rules->time_to_die = num * 1000;
		else if (i == 3)
			rules->time_to_eat = num * 1000;
		else if (i == 4)
			rules->time_to_sleep = num * 1000;
		else
			rules->nb_to_eat = num;
		i++;
	}
	if (i != 6)
		rules->nb_to_eat = 0;
	return (true);
}

int	main(int argc, char **argv)
{
	t_rules			rules;
	t_un_philo		*philo;
	pthread_mutex_t	*fork;

	if (check_arg(argv, argc) == false)
		return (1);
	rules_init(&rules, argv, 1);
	fork = malloc(sizeof(pthread_mutex_t) * rules.nb_philo);
	if (!fork)
		return (1);
	forks_init(fork, rules.nb_philo);
	if (check_zero(rules, argc, fork) == false)
		return (1);
	philo = malloc(sizeof(t_un_philo) * rules.nb_philo);
	if (!philo)
	{
		free(fork);
		return (1);
	}
	philo_init(&rules, philo, fork);
	if (eat_checker(philo, rules) == false)
		return (1);
}
