#include "ft_ls.h"

static void	ft_switch_file(t_env *env)
{
	t_file		*tmp;

	tmp = env->file;
	env->file->nxt = env->file->nxt->nxt;
	env->file->pvs = tmp->nxt;
	if (env->file->nxt)
		env->file->nxt->pvs = env->file;
	env->file->pvs->nxt = env->file;
	env->file->pvs->pvs = tmp->pvs;
	if (env->file->pvs->pvs)
		env->file->pvs->pvs->nxt = tmp->pvs;
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
		while (env->file->pvs)
			env->file = env->file->pvs;
		while (env->file->nxt)
		{
			if (ft_strcmp(env->file->dirent->d_name,
				env->file->nxt->dirent->d_name) > 0)
				ft_switch_file(env);
			env->file = env->file->nxt;
		}
	}
	while (env->file->pvs)
		env->file = env->file->pvs;
	return ;
}
/*
void		ft_sort_t_ls(t_env *env)
{

	return ;
}

void		ft_sort_r_ls(t_env *env)
{

	return ;
}
*/
