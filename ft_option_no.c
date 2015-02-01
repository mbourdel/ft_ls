/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 17:03:07 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/01 17:15:18 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_option_no(DIR *dir)
{
	t_dirent	*file;

	while ((file = readdir(dir)) != NULL)
		if (file->d_name[0] != '.')
			ft_putendl(file->d_name);
	return ;
}
