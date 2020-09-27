/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_champ_mgr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:00:00 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:14:46 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

inline static t_vasa	*ft_create_footer(t_vasa **subchain_head)
{
	t_vasa				*current;
	t_error				*footer;

	footer = NULL;
	if (!(footer = (t_error *)ft_memalloc(sizeof(t_error) + 1)))
	{
		ft_err_malloc("footer", __func__);
		ft_lstdel((t_list **)subchain_head, &ft_del);
		ft_manage_world(NULL);
	}
	current = *subchain_head;
	footer->errmessage = "================================================\n\n";
	ft_lstadd((t_list **)subchain_head, ft_lstnew_r(footer, sizeof(t_error)));
	if (*subchain_head == current)
	{
		ft_err_malloc("subchain_head or footer", __func__);
		free(footer);
		footer = NULL;
		ft_lstdel((t_list **)subchain_head, &ft_del);
		ft_manage_world(NULL);
	}
	return (*subchain_head);
}

inline static t_vasa	*ft_create_header(t_vasa **subchain_head,
													char *filename)
{
	t_vasa				*current;
	t_error				*header;

	if (!(header = (t_error *)ft_memalloc(sizeof(t_error))))
	{
		ft_err_malloc("header", __func__);
		ft_lstdel((t_list **)subchain_head, &ft_del);
		ft_manage_world(NULL);
	}
	current = *subchain_head;
	header->argv_tar = filename;
	header->errmessage = "\n\t\tErrors detected while parsing Champion!";
	ft_lstadd((t_list **)subchain_head,
							ft_lstnew_r((void *)header, sizeof(t_error)));
	if (*subchain_head == current)
	{
		ft_err_malloc("new subchain_head", "ft_lstnew_r");
		free(header);
		header = NULL;
		ft_lstdel((t_list **)subchain_head, &ft_del);
		ft_manage_world(NULL);
	}
	return (*subchain_head);
}

inline static void		ft_flush_char(t_champ *this)
{
	this->id = 0;
	this->size = 0;
	ft_bzero((void *)this->name, (size_t)(DESC_BLOCK + (REG_SIZE + 1) * 2));
	if (this->body)
		free(this->body);
	this->body = NULL;
}

/*
**	Our subchain (errors of the Champion file parsing) is reversed the same way
**	as chain (errors of argvs parsing). But we don't want it that way.
**	That's why:
**	1. We add footer, so subchain looked like footer->err3->err2->err1->NULL
**	2. We rotate subchain: err1->err2->err3->footer->NULL, *subchain_head = err1
**	3. We add header: header->err1->err2->err3->footer->NULL.
**	&footer == tail so we join chans with tail->next = *chain_head;
**	Last step is to update joined chain head with *chain_head = *subchain_head.
*/
/*
**	//? В процессе проверки.
*/

int						ft_ch_err_manager(char *filename,
					t_vasa **subchain_head, t_vasa **chain_head, t_champ *this)
{
	t_vasa			*tail;

	tail = ft_create_footer(subchain_head);
	*subchain_head = (t_vasa *)ft_lstrot_rec((t_list *)*subchain_head, NULL);
	*subchain_head = ft_create_header(subchain_head, filename);
	tail->next = *chain_head;
	*chain_head = *subchain_head;
	ft_flush_char(this);
	return (0);
}
