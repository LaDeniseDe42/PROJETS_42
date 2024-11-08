/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:54:39 by qdenizar          #+#    #+#             */
/*   Updated: 2023/04/25 13:13:04 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# define NC "\e[0m"
# define YELLOW "\e[33m"
# define RED "\e[31m"
# define GREEN "\e[32m"

typedef struct s_rules
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_philo;
	int				nb_to_eat;
	long long		milli_s;
	pthread_mutex_t	msg;
}					t_rules;

typedef struct s_philo
{
	pthread_t		platon;
	int				id;
	int				eated;
	long long		last_eat;
	int				is_eating;
	pthread_mutex_t	*fork;
	t_rules			*rules;
}					t_un_philo;

//UTILS
int			ft_strlen(const char *s);
void		print_error(char *message);
int			ft_isdigit(char c);
int			ft_isign(char c);
int			ft_atoi(char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_itoa(int i);
void		free_and_stop(struct s_philo *philo);

//Check ARGS
bool		check_arg(char **argv, int argc);
bool		argv_with_only_space(char **argv);
bool		is_digit_sign_or_space(char **argv);
bool		is_empty(char **argv);
bool		true_or_false(int i, int j, char **argv);
bool		arg_number(int argc);
bool		check_zero(struct s_rules rules, int argc, pthread_mutex_t *fork);

//eat_for_your_life
bool		eat_checker(struct s_philo *philo, struct s_rules rules);
void		print_script(int ms, int id, char *str, pthread_mutex_t *mutex);
void		print_script_helper(char *str);
int			wait_threads(t_un_philo *philo);
void		eat_eat_eat(t_un_philo	*p);
void		reduce_lines(struct s_philo *philo, struct s_rules rules, int i);

//time_death_and_sleep
long long	how_much_time(void);
bool		is_death(long long last_eat, int time_to_die);
void		ft_sleep(int t);

//main
void		*start_routine(void *arg);

#endif