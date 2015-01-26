/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:46:04 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/26 17:04:16 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_pwd_env(char **envp)
{
	char	*pwd;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'W' && envp[i][2] == 'D')
			pwd = ft_strdup((envp[i] + 4));
		i++;
	}
	if (*pwd)
		return (pwd);
	return (NULL);
}
