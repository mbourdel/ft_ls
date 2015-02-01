/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 18:38:22 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/01 18:41:31 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(t_env env)
{
	ft_putendl(ft_strjoin(ft_strjoin("ls: ", (ft_strrchr(env.pwd, '/') + 1)),
				ft_strjoin(": ", strerror(errno))));
	return ;
}
