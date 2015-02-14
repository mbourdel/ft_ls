/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:50:29 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/09 12:52:56 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
void			ft_printoption(t_env *env)
{
	ft_putendl("-------------");
	ft_putendl("list of option(s) :");
	if (env->option.error == 0)
	{
		if (env->option.a == 1)
			ft_putendl("-a");
		if (env->option.l == 1)
			ft_putendl("-l");
		if (env->option.r1 == 1)
			ft_putendl("-r");
		if (env->option.r2 == 1)
			ft_putendl("-R");
		if (env->option.t == 1)
			ft_putendl("-t");
	}
	else
		ft_putendl("they are an error motherfucker :)");
}
*/
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

static void		ft_error_option(char *str)
{
	char	c[2];

	c[0] = str[0];
	c[1] = '\0';
	ft_putendl(ft_strjoin("ls: illegal option -- ", c));
	ft_putendl("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	return ;
}

static void		ft_attribute_option(char *str, t_option *option)
{
	if (str[1])
	{
		if (str[1] == 'a')
			option->a = 1;
		else if (str[1] == 'l')
			option->l = 1;
		else if (str[1] == 't')
			option->t = 1;
		else if (str[1] == 'r')
			option->r1 = 1;
		else if (str[1] == 'R')
			option->r2 = 1;
		else
		{
			ft_error_option(str + 1);
			option->error = 1;
			return ;
		}
		ft_attribute_option(str + 1, option);
	}
	return ;
}

static void		ft_which_one(char *str, t_option *option)
{
	if (str[1] == '-' && !str[2])
		option->no = 1;
	else if (str[1] == '-' && str[2] && !option->no)
	{
		ft_putendl(ft_strjoin("ls: illegal option -- ", "-"));
		ft_putendl(ft_strjoin("usage: ls ",
				"[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]"));
		option->error = 1;
		return ;
	}
	else if (str[1])
		ft_attribute_option(str, option);
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
			ft_which_one(av[i], &env->option);
		else
		{
			env->pwd = ft_strjoin(env->pwd, "/");
			env->pwd = ft_strjoin(env->pwd, av[i]);
		}
		i++;
	}
	return ;
}
