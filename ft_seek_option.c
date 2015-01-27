/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:50:29 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/27 14:06:04 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_which_one(char *str, t_option *option)
{
	if (str[1] == '-' && !str[2])
		option->no = 1;
	return ;
}

t_option		ft_seek_option(int ac, char **av)
{
	t_option	option;
	int			i;

	i = 1;
	while (av[i] && ac)
	{
		if (av[i][0] == '-')
			ft_which_one(av[i], &option);
	}
	return (option);
}
