/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:19:44 by qdenizar          #+#    #+#             */
/*   Updated: 2023/04/25 14:09:18 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//verification nombre arguments
bool	arg_number(int argc)
{
	if (argc != 5 && argc != 6)
	{
		print_error("bad numbers of arguments");
		return (false);
	}
	else
		return (true);
}

//verification anti 0
bool	check_zero(struct s_rules rules, int argc, pthread_mutex_t *fork)
{
	if (rules.nb_philo == 0 || rules.time_to_sleep == 0
		|| rules.time_to_die == 0 || rules.time_to_eat == 0)
	{
		print_error("0 is not allowed in this program");
		return (false);
	}
	if (argc == 6 && rules.nb_to_eat == 0)
	{
		print_error("0 is not allowed in this program");
		return (false);
	}
	if (rules.nb_philo == 1)
	{
		printf("\e[31mAfter 0ms \e[33mphilo number 1 \e[32mhas taken a fork\n");
		printf("\e[31mAfter %dms \e[33mphilo number 1 \e[32mdied\n",
			rules.time_to_die / 1000);
		free(fork);
		return (false);
	}
	return (true);
}
