/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:11:13 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/09 17:48:30 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */*

#include "ft_ls.h"

static int		ft_put_one_file(t_env *env)
{
	t_file		*nfile;

	nfile = (t_file*)malloc(sizeof(t_file));
	if ((nfile->dirent = readdir(env->dir)) == NULL)
		return (0);
	if (stat(ft_strjoin(env->pwd, ft_strjoin("/", nfile->dirent->d_name)), &nfile->stat))
		ft_error(*env);
	nfile->nxt = env->file;
	nfile->pvs = NULL;
	if (env->file != NULL)
		env->file->pvs = nfile;
	env->file = nfile;
	return (1);
}

void			ft_get_the_files(t_env *env)
{
	env->file = NULL;
	while (ft_put_one_file(env))
		if (errno)
			ft_error(*env);
	return ;
}
