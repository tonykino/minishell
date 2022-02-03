/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_out_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:59:16 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/03 22:54:37 by buschiix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "env.h"
#include "str.h"
#include "print.h"
#include "minishell_signal.h"
#include "expander.h"
#include "error.h"

static void	_son(char **cmd, t_data *data)
{
	char	**env_cpy;
	char	*path;

	signal_fork();
	env_cpy = env_switch(data, 0);
	str_free(data->pwd);
	path = expander_path(cmd[0], data->env);
	execve(path, cmd, env_cpy);
	print_error(cmd[0], ": command not found\n", 0, 0);
	str_free_list(cmd);
	str_free_list(env_cpy);
	str_free(path);
	env_del_all(data->env);
	exit(127);
}

void	exe_out_process(t_command *cmd, t_data *data)
{
	cmd->pid = fork();
	if (!cmd->pid)
	{
//		if (cmd->fd_in != 0)
//		{
//			dup2(cmd->fd_in, 0);
//			close(cmd->fd_in);
//			close(cmd->fd_tmp);
//		}
//		if (cmd->fd_out != 1)
//		{
//			dup2(cmd->fd_out, 1);
//			close(cmd->fd_out);
//			close(cmd->fd_tmp);
//		}
		if (data->pipefd[0] != 0)
			close(data->pipefd[0]);
		_son(cmd->args, data);
	}
	signal_ignore();
}
