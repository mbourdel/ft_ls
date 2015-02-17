/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:38:17 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/17 18:30:02 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_aff_l(char *right, nlink_t nb, char *uid,/* gid_t gid,*/off_t size, int date, char *name)
{
	ft_putstr(right);
	if (nb < 100)
		ft_putchar(' ');
	if (nb < 10)
		ft_putchar(' ');
	ft_putstr("  ");
	ft_putnbr(nb);
	ft_putchar(' ');
	ft_putstr(uid);
	ft_putchar(' ');
//	ft_putstr(gid);
//	ft_putchar(' ');
	ft_putnbr((int)size);
	ft_putchar(' ');
	ft_putstr(ft_itoa(date));
	ft_putchar(' ');
	ft_putendl(name);
	return ;
}

static char		*ft_right(t_stat stat)
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
	char		*right;
	t_passwd	*pwuid;

	while (env->file != NULL)
	{
		pwuid = getpwuid(env->file->stat.st_uid);
		right = ft_right(env->file->stat);
		if (env->file->dirent->d_name[0] != '.' || env->option.a == 1)
			//ft_putendl(ft_strjoin(right, ft_strjoin("\t", env->file->dirent->d_name)));
			ft_aff_l(right, env->file->stat.st_nlink, pwuid->pw_name, env->file->stat.st_size, env->file->stat.MTIME, env->file->dirent->d_name);
		free(right);
		env->file = env->file->nxt;
	}
	return ;
}







