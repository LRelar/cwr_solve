/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_f_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 13:01:34 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:08:37 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
TODO: Проверить на валгринде.
*/

void		ft_err_fn_notnbr(t_vasa **head, void *object)
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
	error->errmessage = "Inapropriate parameter given to the flag -n.";
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

void		ft_err_fn_inter(t_vasa **head, void *object)
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
	error->errmessage = "The parameter > MAX_PLAYERS. ID'll be auto assigned.";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		ft_err_malloc("new_head", "ft_lstnew_r");
		free(error);
		error = NULL;
		ft_manage_world(NULL);
	}
}
