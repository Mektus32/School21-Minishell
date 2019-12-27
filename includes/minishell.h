#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
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
void	sh_init(t_min *sh, char **av, char **env);

/*
 * input_prompt.c
 */
void	input_prompt(t_min sh);

/*
 * useful.c
 */
char	*ft_getenv(const char *name, t_min sh);
void	start_program(const char *name, t_min sh);
char	*get_program(const char **dirs, const char *name, t_min sh);

/*
 * check_commands.c
 */
void	check_command(t_min *sh);

/*
 * commands.c
 */
void	cd(t_min *sh);

#endif
