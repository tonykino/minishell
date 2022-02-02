/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:44:54 by rgeny             #+#    #+#             */
/*   Updated: 2022/02/02 13:52:46 by buschiix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <readline/history.h>
#include "error.h"
#include "env.h"
#include "expander.h"
#include "exe.h"
#include "lexer.h"
#include "parser.h"
#include "minishell_signal.h"
#include "cleaner.h"


int	g_last_return;
static void	_init(char *envp[], t_data *data)
{
	t_env	*pwd;

	g_last_return = 0;
	data->env = 0;
	env_init(&data->env, envp);
	data->pwd = 0;
	data->tokens = NULL;
	data->ast_root = NULL;
	pwd = env_find(data->env, "PWD");
	if (pwd)
		data->pwd = str_dup(pwd->value);
	data->interactive.line = 0;
	if (!isatty(0) || !isatty(1) || !isatty(2))
		data->interactive.is_interactive = 0;
	else
		data->interactive.is_interactive = 1;
}

static void	_t1(t_carg *args)
{
	while (args)
	{
		printf("%s\n", args->content);
		args = args->next;
	}
	printf("\n\n");
}

static void	_exe(t_data *data)
{
	char	*rl;
	int		in;
	int		out;

	rl = exe_readline(data);
	while (rl && str_cmp(rl, "exit"))
	{
		add_history(rl);
		data->tokens = lexer_lex(rl);
		if (data->tokens && parse_tokens(data, data->tokens) == 0)
		{
//			_t1(data->ast_root->command->cargs);
			// lexer_print_tokens(data->tokens); 
			// print_ast(data->ast_root, 0);
			expander_main(data, data->ast_root);
			in = dup(0);
			out = dup(1);
			exe_main(data->ast_root, data);
			dup2(in, 0);
			dup2(out, 1);
			close(in);
			close(out);
		}
		str_free(rl);
		lexer_free_tokens(&data->tokens);
		free_ast(data->ast_root);
		rl = exe_readline(data);
	}
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/time.h>
//#include <sys/resource.h>

int	main(__attribute((unused)) int argc,
	__attribute__((unused)) char *argv[], char *envp[])
{
//	struct rlimit	l;
	t_data	data;

//	getrlimit(RLIMIT_MEMLOCK, &l);
//	l.rlim_cur = 1;
//	setrlimit(RLIMIT_MEMLOCK, &l);
	signal_current();
	_init(envp, &data);
	_exe(&data);
	if (data.interactive.is_interactive)
		write(1, "exit\n", 5);
	clean_all(&data);
	return (g_last_return);
}
