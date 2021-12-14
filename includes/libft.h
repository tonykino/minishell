/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:26:48 by rgeny             #+#    #+#             */
/*   Updated: 2021/12/14 21:05:59 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>

char	**ft_split(char *s, char *charset);
char	*str_ndup(const char *s, int n);
int		str_cmp(char *s1, char *s2);
void	*mem_set(void *b, int c, size_t len);
void	*mem_cpy(void *dst, const void *src, size_t n);
int		get_min(int a, int b);
int		str_len(const char *s);
#endif
