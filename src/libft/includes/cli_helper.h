/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 21:52:24 by andru196          #+#    #+#             */
/*   Updated: 2020/09/13 22:18:20 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_HELPER_H
# define CLI_HELPER_H

typedef struct s_arg	t_arg;

struct					s_arg
{
	char				*names;
	char				*description;
	char				*value;
	char				isflag;
	char				hasvalue;
	t_arg				*next;
};

typedef struct			s_args_rez
{
	char				has_args;
	t_arg				*flags;
	t_list				*not_expected;
	t_arg				*args;
}						t_args_rez;

void					args_anal(char **args, int argc, t_args_rez *ret);
t_arg					*add_arg(t_args_rez *args, char isflag, char *names, \
																	char *desc);
t_args_rez				*new_arguments_cont();
void					free_args_rez(t_args_rez **args);

#endif
