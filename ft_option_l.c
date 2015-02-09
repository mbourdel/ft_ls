/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:38:17 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/09 18:16:59 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_type(t_stat stat)
{
	char	*res;

	res = ft_memalloc(11);
	S_ISDIR(stat.st_mode) ? (res[0] = 'd') : (res[0] = '-');
	res[1] = '-';
	res[2] = '-';
	res[3] = '-';
	res[4] = '-';
	res[5] = '-';
	res[6] = '-';
	res[7] = '-';
	res[8] = '-';
	res[9] = '-';
	res[10] = '\0';
	return (res);
}

void			ft_option_l(t_env *env)
{
	char	*yolo;
	while (env->file != NULL)
	{
		yolo = ft_type(env->file->stat);
		if (env->file->dirent->d_name[0] != '.' || env->option.a == 1)
			ft_putendl(ft_strjoin(yolo, ft_strjoin("\t", env->file->dirent->d_name)));
		free(yolo);
		env->file = env->file->nxt;
	}
	return ;
}







