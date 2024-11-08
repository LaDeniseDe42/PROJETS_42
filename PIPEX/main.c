/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:14:38 by qdenizar          #+#    #+#             */
/*   Updated: 2023/03/16 15:04:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_my_child	child;
	int			pipe_fd[2];

	init_my_child(&child);
	if (argc != 5)
		print_error("Arguments numbers not egal to 4");
	child.fd = open(argv[1], O_RDONLY);
	child.fd2 = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (child.fd2 == -1 || child.fd == -1)
		print_error_f("zsh: no such file or directory: ", argv);
	if (pipe(pipe_fd) == -1)
		print_error("An error ocurred with opening the pipe");
	child.henry = fork();
	if (child.henry < 0)
		print_error("An error ocurred with opening the fork");
	if (child.henry == 0)
		go_work_henry(child, argv, env, pipe_fd);
	if (child.henry > 0)
		odile_quest(child, argv, env, pipe_fd);
	waitpid(child.fd, NULL, 0);
	waitpid(child.fd2, NULL, 0);
	close(child.fd);
	close(child.fd2);
	return (0);
}

void	init_my_child(t_my_child *child)
{
	child->fd = 0;
	child->fd2 = 0;
	child->henry = 0;
	child->i = 0;
	child->total_path = NULL;
	child->split_cmd1_for_my_son = NULL;
	child->cmd_slash = NULL;
	child->cmd_path = NULL;
	child->odile = 0;
	child->split_cm2_for_my_second_son = NULL;
	child->cmd = 0;
}
