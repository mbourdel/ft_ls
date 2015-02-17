/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:40:10 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/17 16:16:42 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av, char **envp)
{
	t_env		env;

	ft_putendl(MTIME);
	ft_init_option(&env.option);
	env.dir = NULL;
	if (!envp[0])
		return (0);
	env.pwd = ft_pwd_env(envp);
	if (*env.pwd)
	{
		ft_seek_option(&env, ac, av);
		if (!env.option.error)
		{
			env.dir = opendir(env.pwd);
			if (env.dir == NULL)
				ft_error(env);
			else
			{
				ft_get_the_files(&env);
				ft_sort_nm_ls(&env);
				if (env.option.l)
					ft_option_l(&env);
				else if (env.option.a)
					ft_option_a(&env);
				else
					ft_option_no(&env);
			}
		}
	}
	else
		ft_putendl("No Pwd WTF??");
//	ft_printoption(&env);
	return (0);
}
