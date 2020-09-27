/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 18:22:44 by tanya             #+#    #+#             */
/*   Updated: 2020/08/20 00:50:54 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cli_helper.h"

static void	del_lst(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

void		free_args_rez(t_args_rez **args)
{
	t_arg *tmp;

	if (!args || !(*args))
		return ;
	while ((*args)->flags)
	{
		tmp = (*args)->flags->next;
		free((*args)->flags);
		(*args)->flags = tmp;
	}
	while ((*args)->args)
	{
		tmp = (*args)->args->next;
		if ((*args)->args->value)
			free((*args)->args->value);
		free((*args)->args);
		(*args)->args = tmp;
	}
	if ((*args)->not_expected)
		ft_lstdel(&(*args)->not_expected, *del_lst);
	free(*args);
	*args = NULL;
}
