/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:55:55 by tokino            #+#    #+#             */
/*   Updated: 2022/02/08 10:37:09 by buschiix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include "t_ast.h"

void	lst_carg_add_back(t_carg **lst, t_carg *new);
void	lst_carg_add_after(t_carg *after, t_carg *new);
void	lst_new_after(t_carg *current, char *new_content);
#endif
