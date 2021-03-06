/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ft_ssl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <curquiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:59:42 by curquiza          #+#    #+#             */
/*   Updated: 2019/04/30 19:00:39 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_ex_ret	is_option(char *arg, t_state *state)
{
	return (state->opt_end == FALSE && arg && arg[0] == '-' && arg[1]);
}

static t_bool	is_option_breaker(t_state *state, char *arg)
{
	return (state->opt_end == FALSE && ft_strcmp(arg, "--") == 0);
}

static t_ex_ret	parse_and_execute_arg(char *arg, char *next_arg, t_state *state)
{
	if (is_option_breaker(state, arg) == FALSE)
	{
		if (is_option(arg, state))
		{
			apply_option(arg, next_arg, state);
			return (SUCCESS);
		}
		state->output = TRUE;
		state->opt_end = TRUE;
		return (apply_file(arg, state));
	}
	state->opt_end = TRUE;
	state->output = TRUE;
	return (SUCCESS);
}

static t_bool	need_last_stdin_reading(t_state *state)
{
	return (state->output == FALSE
		&& (opt_is_activated(state->options, OPTION_R)
			|| opt_is_activated(state->options, OPTION_Q)
			|| !opt_is_activated(state->options, OPTION_P)));
}

t_ex_ret		run_ft_ssl(char **argv, t_state *state)
{
	t_ex_ret	ret;

	ret = SUCCESS;
	while (*argv)
	{
		if (parse_and_execute_arg(*argv, *(argv + 1), state) == FAILURE)
			ret = FAILURE;
		if (state->opt_s)
		{
			state->opt_s = FALSE;
			argv++;
		}
		if (*argv)
			argv++;
	}
	if (ret == SUCCESS && need_last_stdin_reading(state))
		apply_stdin(state);
	return (ret);
}
