/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apl_to_my_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:30:32 by qdenizar          #+#    #+#             */
/*   Updated: 2023/03/14 12:09:32 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	verif_cmd(char **argv)
{
	int	cmd;

	cmd = 0;
	if (argv[2][0] == '/' && argv[3][0] != '/')
		cmd = 1;
	else if (argv[3][0] == '/' && argv[2][0] != '/')
		cmd = 2;
	else if (argv[3][0] == '/' && argv[2][0] == '/')
		cmd = 3;
	return (cmd);
}

void	free_henry(t_my_child child)
{
	free_tab(child.total_path);
	free_tab(child.split_cmd1_for_my_son);
}

void	free_odile(t_my_child child)
{
	free_tab(child.total_path);
	free_tab(child.split_cm2_for_my_second_son);
}

void	scratch_lines_henry(t_my_child child, char **e)
{
	free(child.cmd_slash);
	if (child.cmd_path)
		execve(child.cmd_path, child.split_cmd1_for_my_son, e);
}

void	scratch_lines_odile(t_my_child child, char **e)
{
	free(child.cmd_slash);
	if (child.cmd_path)
		execve(child.cmd_path, child.split_cm2_for_my_second_son, e);
}
