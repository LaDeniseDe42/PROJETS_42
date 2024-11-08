/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_for_your_life.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:57:56 by qdenizar          #+#    #+#             */
/*   Updated: 2023/04/25 14:24:29 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	eat_checker_helper(struct s_philo *philo, struct s_rules rules)
{
	int	eat;

	eat = 1;
	while (eat < rules.nb_philo)
	{
		if (philo[eat].eated >= rules.nb_to_eat)
			eat++;
		else
			break ;
	}
	if (rules.nb_philo > 1)
	{
		if (eat == rules.nb_philo)
			return (false);
	}
	else
	{
		if (eat == rules.nb_philo)
			return (false);
	}
	return (true);
}

bool	eat_checker(struct s_philo *philo, struct s_rules rules)
{
	int	i;

	i = 1;
	while (1)
	{
		if ((is_death(philo[i].last_eat, rules.time_to_die) == true)
			&& philo[i].is_eating == 0)
		{
			reduce_lines(philo, rules, i);
			return (false);
		}
		if (++i == rules.nb_philo)
			i = 0;
		if (rules.nb_to_eat != 0)
		{
			if (eat_checker_helper(philo, rules) == false)
			{
				pthread_mutex_lock(&(philo->rules->msg));
				printf("Thx for this good meal :)\n");
				free_and_stop(philo);
				return (false);
			}
		}
	}
	return (true);
}

void	print_script(int ms, int id, char *str, pthread_mutex_t *mutex)
{
	int		i;
	char	*conv;

	pthread_mutex_lock(mutex);
	i = 0;
	conv = ft_itoa(ms);
	write(1, "\e[31mAfter ", 12);
	while (conv[i])
	{
		write(1, &conv[i], 1);
		i++;
	}
	write(1, "\e[31mms", 8);
	write(1, "\e[33m philo number ", 20);
	i = 0;
	free(conv);
	conv = ft_itoa(id + 1);
	while (conv[i])
	{
		write(1, &conv[i], 1);
		i++;
	}
	free(conv);
	print_script_helper(str);
	pthread_mutex_unlock(mutex);
}

void	print_script_helper(char *str)
{
	int	i;

	i = 0;
	write(1, "\e[32m ", 7);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	wait_threads(t_un_philo *philo)
{
	int	i;
	int	return_code;

	i = 0;
	return_code = 1;
	while (i < philo->rules->nb_philo)
	{
		if (pthread_join(philo[i].platon, NULL))
			return_code = 0;
		i++;
	}
	return (return_code);
}
