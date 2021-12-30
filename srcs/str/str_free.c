/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:36:14 by rgeny             #+#    #+#             */
/*   Updated: 2021/12/30 15:20:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	str_free_s(char *s)
{
	free(s);
}

void	str_free_ss(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		str_free_s(s[i]);
		i++;
	}
	free(s);
}
