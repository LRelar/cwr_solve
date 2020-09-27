/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_champ_content_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:30:40 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:09:09 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
**	Following functions are of their own subtype:
**	Extra ft_lstdel call added in case of insufficient memory to allocate for
**	error structure (we destroy Champion errors subchain).
*/
/*
TODO: Проверить на валгринде.
*/

void		ft_err_invalid_comment(t_vasa **head, void *object)
{
	t_vasa	*current;
	t_error	*error;

	if (!(error = (t_error *)ft_memalloc(sizeof(t_error))))
	{
		ft_err_malloc("error", __func__);
		ft_lstdel((t_list **)head, &ft_del);
		ft_manage_world(NULL);
	}
	current = *head;
	(void)object;
	error->errmessage = "Champion Comment field has ctrl sequences.";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		ft_err_malloc("new_head", "ft_lstnew_r");
		free(error);
		error = NULL;
		ft_manage_world(NULL);
	}
}

/*
TODO: Проверить на валгринде.
*/

void		ft_err_invalid_bodysize(t_vasa **head, void *object)
{
	t_vasa	*current;
	t_error	*error;

	if (!(error = (t_error *)ft_memalloc(sizeof(t_error))))
	{
		ft_err_malloc("error", __func__);
		ft_lstdel((t_list **)head, &ft_del);
		ft_manage_world(NULL);
	}
	current = *head;
	(void)object;
	error->errmessage = "Declared Champion_size does not match with real one.";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		ft_err_malloc("new_head", "ft_lstnew_r");
		free(error);
		error = NULL;
		ft_manage_world(NULL);
	}
}
