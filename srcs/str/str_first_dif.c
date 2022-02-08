/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_first_dif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:40:20 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/05 18:14:52 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_first_dif(const char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}