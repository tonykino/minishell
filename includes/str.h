/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:08:06 by rgeny             #+#    #+#             */
/*   Updated: 2021/12/31 21:48:52 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

char	*str_ndup(const char *s, int n);
int		str_cmp(char *s1, char *s2);
char	*str_join(const char *s1, const char *s2, char c);
char	**str_split(char *s, char *charset);
int		str_len(const char *s, char c);
void	str_free_string(char **s);
#endif
