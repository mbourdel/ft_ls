/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:37:31 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/17 16:07:06 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if ((defined __APPLE__) && (!defined MTIME))
# define MTIME "st_mtimespec.tv_sec"
#elif ((defined __linux) && (!defined MTIME))
# define MTIME "st_mtime"
#endif

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct s_file	t_file;
struct					s_file
{
	t_dirent			*dirent;
	t_stat				stat;
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
void					ft_option_l(t_env *env);

void					ft_get_the_files(t_env *env);

void					ft_sort_nm_ls(t_env *env);
//void					ft_sort_t_ls(t_env *env);
//void					ft_sort_r_ls(t_env *env);

void					ft_error(t_env env);
//void					ft_printoption(t_env *env); // just for test WTF

#endif
