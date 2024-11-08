/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:03:57 by qdenizar          #+#    #+#             */
/*   Updated: 2023/03/16 15:26:39 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	go_work_henry(t_my_child child, char **a, char **e, int *p)
{
	while (e[child.i])
	{
		if (ft_strncmp(e[child.i], "PATH=", 5) == 0)
			break ;
		child.i++;
	}
	child.total_path = ft_split(e[child.i] + 5, ':');
	child.split_cmd1_for_my_son = ft_split(a[2], ' ');
	child.i = 0;
	child.cmd = verif_cmd(a);
	if (child.cmd == 0 || child.cmd == 2)
		child.cmd_slash = ft_strjoin("/", child.split_cmd1_for_my_son[0]);
	else if (child.cmd == 3 || child.cmd == 1)
		child.cmd_slash = a[2];
	help_henry(&child, p);
	if (child.cmd == 0 || child.cmd == 2)
		scratch_lines_henry(child, e);
	if (child.cmd == 3 || child.cmd == 1)
		execve(child.cmd_slash, child.split_cmd1_for_my_son, e);
	print_error_c("zsh: command not found: ", a);
	free_henry(child);
}

void	help_henry(t_my_child *child, int *p)
{
	while (child->total_path[child->i])
	{
		child->cmd_path = ft_strjoin(child->total_path[child->i],
				child->cmd_slash);
		if (access(child->cmd_path, F_OK | X_OK) == -1)
		{
			free(child->cmd_path);
			child->cmd_path = NULL;
			child->i++;
		}
		else
		{
			break ;
		}	
	}
	dup2(child->fd, STDIN_FILENO);
	dup2(p[1], STDOUT_FILENO);
	close(p[0]);
	close(p[1]);
	close(child->fd);
}

void	odile_quest(t_my_child child, char **a, char **e, int *p)
{
	child.odile = fork();
	if (child.odile < 0)
		print_error("An error ocurred with opening the fork");
	if (child.odile == 0)
		go_work_odile(child, a, e, p);
}

void	go_work_odile(t_my_child child, char **a, char **e, int *p)
{
	while (e[child.i])
	{
		if (ft_strncmp(e[child.i], "PATH=", 5) == 0)
			break ;
		child.i++;
	}
	child.total_path = ft_split(e[child.i] + 5, ':');
	child.split_cm2_for_my_second_son = ft_split(a[3], ' ');
	child.i = 0;
	child.cmd = verif_cmd(a);
	if (child.cmd == 0 || child.cmd == 1)
		child.cmd_slash = ft_strjoin("/", child.split_cm2_for_my_second_son[0]);
	if (child.cmd == 2 || child.cmd == 3)
		child.cmd_slash = a[3];
	help_odile(&child, p);
	if (child.cmd == 0 || child.cmd == 1)
		scratch_lines_odile(child, e);
	if (child.cmd == 2 || child.cmd == 3)
		execve(child.cmd_slash, child.split_cm2_for_my_second_son, e);
	print_error_c2("zsh: command not found: ", a);
	free_odile(child);
}

void	help_odile(t_my_child *child, int *p)
{
	while (child->total_path[child->i])
	{
		child->cmd_path = ft_strjoin(child->total_path[child->i],
				child->cmd_slash);
		if (access(child->cmd_path, F_OK | X_OK) == -1)
		{
			free(child->cmd_path);
			child->cmd_path = NULL;
			child->i++;
		}
		else
		{
			break ;
		}	
	}
	dup2(child->fd2, STDOUT_FILENO);
	dup2(p[0], STDIN_FILENO);
	close(p[0]);
	close(p[1]);
	close(child->fd2);
}
