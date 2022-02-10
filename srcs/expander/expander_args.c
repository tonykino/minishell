/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:38:29 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/10 13:02:45 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expand_args(t_command *cmd, t_carg *args, t_data *data, int *arg_n)
{
	t_carg	*prev;
	t_carg	*next;

	prev = NULL;
	while (args)
	{
		if (expand_var(&args->content, data->env))
		{
			(*arg_n)++;
			expand_space_carg(args);
			if (str_len(args->content) != str_clen(args->content, '*'))
				expand_asterisk(cmd, args, NULL);
			expand_quote(args->content);
			prev = args;
			args = args->next;
		}
		else
			lst_del_one(&args, cmd);
	}
}