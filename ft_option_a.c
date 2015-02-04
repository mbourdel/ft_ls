/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:44:14 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/04 17:32:05 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_option_a(t_env *env)
{
	while (env->file != NULL)
	{
		ft_putendl(env->file->dirent->d_name);
		env->file = env->file->nxt;
	}
	return ;
}
