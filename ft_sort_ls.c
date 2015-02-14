#include "ft_ls.h"

static void	ft_switch_file(t_env *env)
{
	t_file		*tmp;


	return ;
}

static int	ft_count_file(t_file *file)
{
	int		i;

	i = 0;
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
	i = ft_cout_file(env->file);
	while (j++ <= i)
	{
		while (env->file->nxt)
		{
			if (ft_strcmp(env->file->dirent->d_name, env->file->dirent->d_name) > 0)
				ft_switch_file(env);
		}
	}
	return ;
}

void		ft_sort_t_ls(t_env *env)
{

	return ;
}

void		ft_sort_r_ls(t_env *env)
{

	return ;
}
