/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 20:29:33 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 22:00:12 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#define _PLAYER_LIM "This and subsequent champions are beyond MAX_PLAYERS."
/*
**	//? В процессе проверки.
*/
void		ft_err_not_champ(t_vasa **head, void *object)
{
	t_vasa	*current;
	t_error	*error;

	if (!(error = (t_error *)ft_memalloc(sizeof(t_error))))
	{
		ft_err_malloc("error", __func__);
		ft_manage_world(NULL);
	}
	current = *head;
	error->argv_tar = (char *)object;
	error->errmessage = "No champion filename between \"-n\" and the object.";
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
**	//? В процессе проверки.
*/
void		ft_err_invalid_filename(t_vasa **head, void *object)
{
	t_vasa	*current;
	t_error	*error;

	if (!(error = (t_error *)ft_memalloc(sizeof(t_error))))
	{
		ft_err_malloc("error", __func__);
		ft_manage_world(NULL);
	}
	current = *head;
	error->argv_tar = (char *)object;
	error->errmessage = "Given object can't be opoened as a file.";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		free(error);
		error = NULL;
		ft_err_malloc("new_head", "ft_lstnew_r");
		ft_manage_world(NULL);
	}
}

/*
**	//? В процессе проверки.
*/
void		ft_err_champ_limit(t_vasa **head, void *object)
{
	t_vasa	*current;
	t_error	*error;

	if (!(error = (t_error *)ft_memalloc(sizeof(t_error))))
	{
		ft_err_malloc("error", __func__);
		ft_manage_world(NULL);
	}
	current = *head;
	error->argv_tar = (char *)object;
	error->errmessage = _PLAYER_LIM;
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		free(error);
		error = NULL;
		ft_err_malloc("new_head", "ft_lstnew_r");
		ft_manage_world(NULL);
	}
}
