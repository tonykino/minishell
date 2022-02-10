/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:36:14 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/10 18:30:13 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void	str_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

void	str_free_list(char ***s)
{
	int	i;

	if (!*s)
		return ;
	i = 0;
	while ((*s)[i])
	{
		str_free(&(*s)[i]);
		i++;
	}
	free(*s);
	*s = NULL;
}