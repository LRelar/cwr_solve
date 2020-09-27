/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_fdump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:38:10 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:08:10 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
*	ПРОВЕРИЛ. Не проверял ошибку маллока.
*/

void		ft_err_fdump_inter(t_vasa **head, void *object)
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
	error->errmessage =
	"Interval boundaries exceed INT32_MAX limit. I.e. var overflow for -dump.";
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
*	ПРОВЕРИЛ. Не проверял ошибку маллока.
*/
void		ft_err_fdump_notnbr(t_vasa **head, void *object)
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
	error->errmessage = "Inapropriate parameter given to the flag -dump.";
	ft_lstadd((t_list **)head, ft_lstnew_r(error, sizeof(t_error)));
	if (*head == current)
	{
		ft_err_malloc("new_head", "ft_lstnew_r");
		free(error);
		error = NULL;
		ft_manage_world(NULL);
	}
}
