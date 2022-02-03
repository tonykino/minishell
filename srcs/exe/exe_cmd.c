/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:08:26 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/03 23:15:25 by buschiix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "exe.h"
#include <stdio.h>
#include "error.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void	exe_cmd(t_node *cmd, t_data *data)
{
	if (data->fd_in != 0)
	{
		dup2(data->fd_in, 0);
		close(data->fd_in);
	}
	if (data->pipefd[1] != 1)
	{
		dup2(data->pipefd[1], 1);
		close(data->pipefd[1]);
	}
	exe_redir(cmd->command);
	if (cmd->command->arg_nb && cmd->command->args[0])
	{
		exe_builtin(cmd->command->args, data);
		if (g_last_return == -1)
			exe_out_process(cmd->command, data);
	}
}
