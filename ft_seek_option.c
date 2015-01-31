/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:50:29 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/27 19:17:43 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_init_option(t_option *option)
{
	option->no = 0;
	option->a = 0;
	option->l = 0;
	option->t = 0;
	option->r1 = 0;
	option->r2 = 0;
	option->error = 0;
	return ;
}

static void		ft_which_one(char *str, t_option *option)
{
	if (str[1] == '-' && !str[2])
		option->no = 1;
	else if (str[1] == '-' && str[2])
	{
		ft_putendl(ft_strjoin("ls: illegal option -- ", "-"));
		ft_putendl("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
		option->error = 1;
		return ;
	}
	else if (str[1] == 'a')
		option->a = 1;
	if (str[2])
		
	return ;
}

void			ft_seek_option(t_env *env, int ac, char **av)
{
	int			i;

	if (ac == 1)
		env->option.no = 1;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-' && env->option.no != 1)
			ft_which_one(av[i], env->option);
		if (av[i][0] != '-' || env->option.no == 1)
			i = i;
		i++;
	}
	return ;
}
