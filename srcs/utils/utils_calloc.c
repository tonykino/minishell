/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:46:29 by tokino            #+#    #+#             */
/*   Updated: 2022/02/05 14:29:44 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*uti_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = malloc(count * size);
	if (dst == NULL)
	{
		error_print(MALLOC_ERROR, NULL, NULL, ERROR_MALLOC);
		return (NULL);
	}
	uti_bzero(dst, count * size);
	return (dst);
}
