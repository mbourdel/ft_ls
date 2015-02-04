/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:37:31 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/04 19:43:22 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>

typedef struct dirent	t_dirent;

typedef struct s_file	t_file;
struct					s_file
{
	t_dirent			*dirent;
	t_file				*pvs;
	t_file				*nxt;
};

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

typedef struct s_env	t_env;
struct					s_env
{
	char				*pwd;
	DIR					*dir;
	t_file				*file;
	t_option			option;
};

char					*ft_pwd_env(char **envp);
void					ft_init_option(t_option *option);
void					ft_seek_option(t_env *env, int ac, char **av);

void					ft_option_no(t_env *env);
void					ft_option_a(t_env *env);

void					ft_get_the_files(t_env *env);

void					ft_error(t_env env);
#endif
