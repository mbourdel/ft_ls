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
	char		*pwd;
	DIR			*directory;
	t_option	option;

	ft_init_option(&option);
	directory = NULL;
	pwd = ft_pwd_env(envp);
	if (*pwd)
	{
		option = ft_seek_option(ac, av);
		if (option.no)
			ft_putendl("no option??? are you sure?? OMG !!!");
		else if (!option.error)
		{
			directory = opendir(pwd);
			if (directory == NULL)
				ft_putendl(strerror(errno));
			else if (option.a == 1)
				ft_option_a(directory);
		}
	}
	else
		ft_putendl("KAKA");
	return (0);
}
