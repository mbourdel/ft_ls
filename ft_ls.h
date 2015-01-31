/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:37:31 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/27 16:47:18 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>

typedef struct dirent	t_dirent;

typedef struct s_option	t_option;
struct					s_option
{
	int					no;
	int					a;
	int					l;
	int					t;
	int					r1;
	int					r2;
	int					error;
};

char					*ft_pwd_env(char **envp);
void					ft_init_option(t_option *option);
void					ft_seek_option(t_option *option, int ac, char **av);

void					ft_option_a(DIR *dir);
#endif
