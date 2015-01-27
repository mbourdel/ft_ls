/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:40:10 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/27 14:05:44 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av, char **envp)
{
	char		*pwd;
	DIR			*directory;
	t_dirent	*file;

	directory = NULL;
	pwd = ft_pwd_env(envp);
	directory = opendir(pwd);
	if (directory == NULL)
		ft_putstr(strerror(errno));
	else
		while ((file = readdir(directory)) != NULL)
			ft_putendl(file->d_name);
	return (0);
	if (ac > 1)
		ft_putendl(av[1]);
}
