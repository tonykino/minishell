/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:04:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/05 18:14:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H
# include "t_data.h"

void	exe_builtin(char **cmd, char **args, t_data *data);
void	exe_out_process(t_command *cmd, t_data *data);
char	*exe_readline(t_data *data);
void	exe_main(t_node *cmd, t_data *data);
int		exe_redir(t_command *cmd);
void	exe_pipe(t_node *cmd, t_data *data);
void	exe_cmd(t_node *cmd, t_data *data);
#endif
