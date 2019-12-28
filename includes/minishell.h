#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct	s_min
{
	char	*prev_path;
	char	*cur_path;
	char	**line;
	char	**av;
	char	**env;
}				t_min;

/*
 * main.c
 */
void	sh_init(t_min *sh, const char **av, const char **env);

/*
 * input_prompt.c
 */
void	input_prompt(t_min sh);

/*
 * useful.c
 */
char	*ft_getenv(const char *name, t_min sh);
void	start_program(const char *name, t_min sh);
char	*get_program(const char **dirs, const char *name);

/*
 * check_commands.c
 */
int		check_command(t_min *sh);

/*
 * cd.c
 */
void	cd(t_min *sh);
void	change_paths(t_min *sh, char *new_cur, char *new_prev);
void	cd_second_param(t_min *sh);

/*
 * echo.c
 */
void	echo(t_min sh);
int		echo_quotes(int *count_solo, int *count_doub, char **res, char ch);
void	echo_variable(t_min sh, int i, int *j, char **res);
void	echo_output(int count_solo, int count_doub, char **res);

/*
 * env.c
 */
void	env(t_min sh);
void	env_print_error(char *name);
void	ft_unsetenv(const char *name, t_min *sh);
void	ft_unsetenv_new_env(const char *name, t_min *sh, int size);

/*
 * setenv.c
 */
void	ft_setenv(t_min *sh);
void	ft_setenv_add_new(const char *str, t_min *sh, int size);
void	ft_setenv_origin(const char **name, const char **value, int overwrite, t_min *sh);

#endif
