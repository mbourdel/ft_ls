/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 17:03:07 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/03 18:02:02 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_option_no(t_env *env)
{
	while (env->file != NULL)
	{
		ft_putendl("yo");
		if (env->file->dirent->d_name[0] != '.')
			ft_putendl(env->file->dirent->d_name);
		env->file = env->file->nxt;
	}
	return ;
}
