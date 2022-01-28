/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:14:36 by rgeny             #+#    #+#             */
/*   Updated: 2022/01/28 10:39:39 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct.h"
#include "exe.h"

void	exe_main(t_node *cmd, t_data *data)
{
	if (cmd->type == E_NODE_TYPE_PIPE)
		exe_pipe(cmd, data);
	else if (cmd->type == E_NODE_TYPE_COMMAND)
		exe_cmd(cmd, data);
}