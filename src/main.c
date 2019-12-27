#include "minishell.h"

void	sh_init(t_min *sh, char **av, char **env)
{
	sh->prev_path = getcwd(NULL, INT_MAX);
	sh->cur_path = getcwd(NULL, INT_MAX);;
	sh->av = av;
	sh->env = env;
}

int main(int ac, char **av, char **env)
{
	t_min	sh;
	char	*line;

	if (ac > 1) {
		ft_printf("usage: ./minishell\n");
		exit(0);
	}
	sh_init(&sh, av, env);
	while (1)
	{
		input_prompt(sh);
		get_next_line(0, &line);
		sh.line = ft_strsplit(line, ' ');
		if (sh.line[0])
		{
			check_command(&sh);
			ft_frtwarr((void**)sh.line, INT_MAX);
		}
	}
	return (0);
}