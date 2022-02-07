/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_separator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:36:52 by tokino            #+#    #+#             */
/*   Updated: 2022/02/07 14:50:49 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*init_separator_node(t_token *token, t_node *separator_node, t_node *cmd_node)
{
	t_node		*new_separator_node;
	t_node_type	type;

    if (token->type == E_TOKEN_TYPE_PIPE)
        type = E_NODE_TYPE_PIPE;
	else if (token->type == E_TOKEN_TYPE_OR)
		type = E_NODE_TYPE_OR;
	else
		type = E_NODE_TYPE_AND;
	new_separator_node = n_create(type);
	if (new_separator_node == NULL)
		return (NULL);
	if (!separator_node)
		new_separator_node->left = cmd_node;
	else
		new_separator_node->left = separator_node;
	return (new_separator_node);
}
