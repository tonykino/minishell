/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:55:29 by rgeny             #+#    #+#             */
/*   Updated: 2022/01/18 18:06:52 by buschiix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "str.h"

void	env_new_(char *value, t_env **env)
{
	env_new(env, str_ndup("_", 1), str_ndup(value, str_len(value)));
}
