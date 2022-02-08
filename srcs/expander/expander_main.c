/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:54:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/10 02:08:39 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	expand_args(t_command *cmd, t_carg *args, t_data *data)
{
	cmd->arg_nb = 0;
	while (args)
	{
		cmd->arg_nb++;
		expand_var(&args->content, data);
		expand_asterisk(cmd, args, NULL);
		expand_quote(args->content);
		args = args->next;
	}
}

static void	expand_redir(t_command *cmd, t_redir *redir, t_data *data)
{
	while (redir)
	{
		if (redir->type != E_REDIR_TYPE_HEREDOC)
			expand_asterisk(NULL, NULL, redir);
		expand_quote(redir->path);
		if (redir->type == E_REDIR_TYPE_HEREDOC)
		{
			if (cmd->fd_in != STDIN_FILENO)
				close(cmd->fd_in);
			cmd->fd_in = expand_heredoc(redir->path, data);
		}
		redir = redir->next;
	}
}

void	expander_main(t_data *data, t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->cmd)
	{
		expand_args(ast->cmd, ast->cmd->cargs, data);
		expand_redir(ast->cmd, ast->cmd->redirections, data);
	}
	expander_main(data, ast->left);
	expander_main(data, ast->right);
}
