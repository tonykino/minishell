/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_isdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 22:21:28 by rgeny             #+#    #+#             */
/*   Updated: 2021/12/31 22:24:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	uti_isdigit(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
