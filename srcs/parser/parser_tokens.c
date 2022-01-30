/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:21:43 by tokino            #+#    #+#             */
/*   Updated: 2022/01/30 13:46:02 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_command_token(t_token_type type)
{
	return (type == E_TOKEN_TYPE_WORD || type == E_TOKEN_TYPE_REDIRECTION);
}

int	parse_tokens(t_data *data, t_token *tokens)
{
	t_token	*current_token;
	t_node	*n_command;
	t_node	*n_separator;

	current_token = tokens;
	n_separator = NULL;
	if (init_n_command(&current_token, &n_command, n_separator))
		return (print_syntax_error(current_token)); // TODO - Manage malloc error
	while (current_token)
	{
		init_n_separator(&n_separator, n_command);
		if (!current_token->next)
			return (print_syntax_error(current_token));
		current_token = current_token->next;
		if (init_n_command(&current_token, &n_command, n_separator))
			return (print_syntax_error(current_token)); // TODO - Manage malloc error
	}
	if (n_separator)
		data->ast_root = n_separator;
	else
		data->ast_root = n_command;
	return (OK);
}
