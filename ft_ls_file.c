/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:11:13 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/03 18:06:34 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_put_one_file(t_env *env)
{
	t_file		nfile;

	if ((nfile.dirent = readdir(env->dir)) == NULL)
		return (0);
	nfile.dirent->d_name = ft_strdup(nfile.dirent->d_name);
	nfile.nxt = env->file;
	nfile.pvs = NULL;
	if (env->file != NULL)
		env->file->pvs = &nfile;
	env->file = &nfile;
	return (1);
}

void			ft_get_the_files(t_env *env)
{
	env->file = NULL;
	while (ft_put_one_file(env))
		ft_putendl(env->file->dirent->d_name);
	ft_putendl("-----");
	if (errno)
		ft_error(*env);
	return ;
}
