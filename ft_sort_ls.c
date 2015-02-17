/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:01:20 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/17 13:37:58 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_switch_file(t_env *env)
{
	t_dirent		*tmp_d;
	t_stat			tmp_s;

	tmp_d = env->file->dirent;
	tmp_s = env->file->stat;
	env->file->dirent = env->file->nxt->dirent;
	env->file->stat = env->file->nxt->stat;
	env->file->nxt->dirent = tmp_d;
	env->file->nxt->stat = tmp_s;
	return ;
}

static int	ft_count_file(t_file *file)
{
	int		i;

	i = 1;
	while (file->nxt)
	{
		file = file->nxt;
		i++;
	}
	return (i);
}

void		ft_sort_nm_ls(t_env *env)
{
	int			i;
	int			j;

	j = 0;
	i = ft_count_file(env->file);
	while (j++ <= i)
	{
		while (env->file->nxt)
		{
			if (ft_strcmp(env->file->dirent->d_name,
				env->file->nxt->dirent->d_name) > 0)
				ft_switch_file(env);
			env->file = env->file->nxt;
		}
		while (env->file->pvs)
			env->file = env->file->pvs;
	}
	return ;
}
/*
void		ft_sort_t_ls(t_env *env)
{

	return ;
}

void		ft_sort_r_ls(t_env *env)
{
	int			i;
	int			j;

	j = 0;
	i = ft_count_file(env->file);
	while (j++ <= i)
	{
		while (env->file->nxt)
		{
			if (ft_strcmp(env->file->dirent->d_name,
				env->file->nxt->dirent->d_name) < 0)
				ft_switch_file(env);
			env->file = env->file->nxt;
		}
		while (env->file->pvs)
			env->file = env->file->pvs;
	}
	return ;
}
*/
