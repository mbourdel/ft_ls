/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:40:10 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/27 19:12:14 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av, char **envp)
{
	t_env		env;

	ft_init_option(&env.option);
	env.dir = NULL;
	env.pwd = ft_pwd_env(envp);
	if (*env.pwd)
	{
		ft_seek_option(&env, ac, av);
		if (env.option.no)
			ft_putendl("no option??? are you sure?? OMG !!!");
		else if (!env.option.error)
		{
			env.dir = opendir(pwd);
			if (dir == NULL)
				ft_putendl(strerror(errno));
			else if (env.option.a == 1)
				ft_option_a(env.directory);
		}
	}
	else
		ft_putendl("No Pwd WTF??");
	return (0);
}
