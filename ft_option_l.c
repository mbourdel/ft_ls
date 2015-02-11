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
	(stat.st_mode & S_IRUSR) ? (res[1] = 'r') : (res[1] = '-');
	(stat.st_mode & S_IWUSR) ? (res[2] = 'w') : (res[2] = '-');
	(stat.st_mode & S_IXUSR) ? (res[3] = 'x') : (res[3] = '-');
	(stat.st_mode & S_IRGRP) ? (res[4] = 'r') : (res[4] = '-');
	(stat.st_mode & S_IWGRP) ? (res[5] = 'w') : (res[5] = '-');
	(stat.st_mode & S_IXGRP) ? (res[6] = 'x') : (res[6] = '-');
	(stat.st_mode & S_IROTH) ? (res[7] = 'r') : (res[7] = '-');
	(stat.st_mode & S_IWOTH) ? (res[8] = 'w') : (res[8] = '-');
	(stat.st_mode & S_IXOTH) ? (res[9] = 'x') : (res[9] = '-');
	return (res);
}

void			ft_option_l(t_env *env)
{
	char	*yolo;

	ft_putendl(ft_itoa(S_IRUSR));
	ft_putendl(ft_itoa(S_IWUSR));
	ft_putendl(ft_itoa(S_IXUSR));
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







