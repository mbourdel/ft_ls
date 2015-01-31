/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:44:14 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/27 19:11:33 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_option_a(DIR *dir)
{
	t_dirent	*file;

	ft_putendl("OPTION -a BAYARD");
	while ((file = readdir(dir)) != NULL)
		ft_putendl(file->d_name);
	return ;
}
