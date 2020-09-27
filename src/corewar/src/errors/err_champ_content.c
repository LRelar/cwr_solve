/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_champ_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:10:17 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:00:03 by ycorrupt         ###   ########.fr       */
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

void		ft_err_invalid_cwr_magic(t_vasa **head, void *object)
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
	error->errmessage = "Given champion file holds wrong exec magic value.";
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

void		ft_err_invalid_filesize(t_vasa **head, void *object)
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
	error->argv_tar = object;
	error->errmessage = "Given champion file ended unexpectedly.";
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

void		ft_err_invalid_name(t_vasa **head, void *object)
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
	error->errmessage = "Champion Name field has ctrl sequences.";
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

void		ft_err_invalid_champsize(t_vasa **head, void *object)
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
	error->errmessage = "Declared champion size exceeds limits.";
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

void		ft_err_invalid_separator(t_vasa **head, void *object)
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
	error->argv_tar = object;
	error->errmessage = "Inappropriate separator";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		ft_err_malloc("new_head", "ft_lstnew_r");
		free(error);
		error = NULL;
		ft_manage_world(NULL);
	}
}
