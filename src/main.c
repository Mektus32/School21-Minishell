#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_min	sh;
	char	*line;
	pid_t	pid;

	if (ac > 1) {
		ft_printf("usage: ./minishell\n");
		exit(0);
	}
	sh.av = av;
	sh.env = env;
	while (1)
	{
		input_prompt(sh);
		get_next_line(0, &line);
		sh.line = ft_strsplit(line, ' ');
		check_command(&sh);
	}
	return (0);
}