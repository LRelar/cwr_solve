/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 13:02:27 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:02:43 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <cwr_man.h>

void			ft_err_nochamps(t_vasa **head, void *object)
{
	t_vasa	*current;
	t_error	*error;

	(void)object;
	if (!(error = (t_error *)ft_memalloc(sizeof(t_error))))
	{
		ft_err_malloc("error", __func__);
		ft_manage_world(NULL);
	}
	current = *head;
	(void)object;
	error->errmessage = "No valid champions were given. Arena is empty.";
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
**	This funtion is about common error message, occurred if given argv is not
**	recognized.
**	Comment is useful!
*/

void			ft_err_invalid_parameter(t_vasa **head, void *object)
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
	error->errmessage = "Given object is not recognized as valid parameter.";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		ft_err_malloc("new_head", "ft_lstnew_r");
		free(error);
		error = NULL;
		ft_manage_world(NULL);
	}
}

void			ft_err_id_doubled(t_vasa **head, void *object)
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
	error->errmessage = "Champion given non-unique ID. ID'll be autoassigned.";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		ft_err_malloc("new_head", "ft_lstnew_r");
		free(error);
		error = NULL;
		ft_manage_world(NULL);
	}
}

void			ft_err_id_behind_fighters(t_vasa **head, void *object)
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
	error->errmessage = "Given ID > amount of eligible champions.";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		ft_err_malloc("new_head", "ft_lstnew_r");
		free(error);
		error = NULL;
		ft_manage_world(NULL);
	}
}

void			ft_show_man(void)
{
	ft_printf_fd(2, "\033[1mNAME{eoc}\n\tcorewar %s", \
			"-- battle arena for corewar game.");
	ft_printf_fd(2, "\n\033[1mSYNOPSIS{eoc}\n\t%s\n", \
			MAN_SYN);
	ft_printf_fd(2, "\033[1mDESCRIPTION{eoc}\n\t%s%s", \
			MAN_DESC_1, MAN_DESC_2);
	ft_printf_fd(2, "%s%s%s%s", \
			MAN_DESC_3, MAN_DESC_4, MAN_DESC_5, MAN_DESC_6);
	ft_printf_fd(2, "%s%s%s%s", \
			MAN_DESC_7, MAN_DESC_8, MAN_DESC_9, MAN_DESC_10);
	ft_printf_fd(2, MAN_DESC_11, MAX_PLAYERS);
}
