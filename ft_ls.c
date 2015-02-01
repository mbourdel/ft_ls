/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:40:10 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/01 17:26:48 by mbourdel         ###   ########.fr       */
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
		ft_putendl(env.pwd);
		ft_seek_option(&env, ac, av);
		ft_putendl(env.pwd);
		if (!env.option.error)
		{
			env.dir = opendir(env.pwd);
			if (env.dir == NULL)
				ft_putendl(strerror(errno));
			else if (env.option.a)
				ft_option_a(env.dir);
			else if (env.option.no == 1)
				ft_option_no(env.dir);
		}
	}
	else
		ft_putendl("No Pwd WTF??");
	return (0);
}
