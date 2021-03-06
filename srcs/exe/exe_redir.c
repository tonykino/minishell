/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 08:52:26 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/15 10:46:33 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

static int	_open_redir_stdin(t_redir *redir, int *fd_in)
{
	close_fd(fd_in, STDIN_FILENO);
	if (access(redir->path, F_OK) != SUCCESS)
		return (error_print(redir->path, NO_FILE, NULL, ERROR_EXEC));
	if (access(redir->path, R_OK) != SUCCESS)
		return (error_print(redir->path, PERMISSION_DENIED, NULL, ERROR_EXEC));
	*fd_in = open(redir->path, O_RDONLY);
	return (SUCCESS);
}

static int	_open_redir_stdout(t_redir *redir, int *fd_out, int o_append)
{
	close_fd(fd_out, STDOUT_FILENO);
	if (access(redir->path, F_OK) == SUCCESS
		&& access(redir->path, W_OK) != SUCCESS)
		return (error_print(redir->path, PERMISSION_DENIED, NULL, ERROR_EXEC));
	*fd_out = open(redir->path, O_WRONLY | O_CREAT | o_append,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (SUCCESS);
}

static int	_dup_heredoc(int *fd_in, int fd_heredoc)
{
	close_fd(fd_in, STDIN_FILENO);
	if (fd_heredoc != STDIN_FILENO)
	{
		*fd_in = dup(fd_heredoc);
		if (*fd_in == -1)
			*fd_in = STDIN_FILENO;
	}
	return (SUCCESS);
}

static void	_set_fd(int fd_in, int fd_out, int fd_heredoc, t_data *data)
{
	if (fd_in != STDIN_FILENO)
	{
		if (data->pipefd[0] != STDIN_FILENO)
			close(data->pipefd[0]);
		data->pipefd[0] = fd_in;
	}
	if (fd_out != STDOUT_FILENO)
	{
		if (data->pipefd[1] != STDOUT_FILENO)
			close(data->pipefd[1]);
		data->pipefd[1] = fd_out;
	}
	if (fd_heredoc != STDIN_FILENO)
		close(fd_heredoc);
}

void	exe_redir(t_redir *redir, int fd_heredoc, t_data *data)
{
	int	fd_in;
	int	fd_out;

	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	while (redir != NULL && !is_error())
	{
		expand_redir(redir, data);
		if (is_error())
			break ;
		if (redir->type == E_REDIR_TYPE_STDIN)
			_open_redir_stdin(redir, &fd_in);
		else if (redir->type == E_REDIR_TYPE_STDOUT)
			_open_redir_stdout(redir, &fd_out, O_TRUNC);
		else if (redir->type == E_REDIR_TYPE_HEREDOC)
			_dup_heredoc(&fd_in, fd_heredoc);
		else if (redir->type == E_REDIR_TYPE_APPEND)
			_open_redir_stdout(redir, &fd_out, O_APPEND);
		redir = redir->next;
	}
	_set_fd(fd_in, fd_out, fd_heredoc, data);
}
