/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:44:14 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/01 17:15:31 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_option_a(DIR *dir)
{
	t_dirent	*file;

	while ((file = readdir(dir)) != NULL)
		ft_putendl(file->d_name);
	return ;
}
