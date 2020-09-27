/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gls_supp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:26:52 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:06:57 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wipegnl(t_list **fdl, t_list *first, t_list *second, t_list *third)
{
	*fdl = NULL;
	(void)first;
	if (second)
		ft_lstdel(&second, ft_del);
	if (third)
		ft_lstdel(&third, ft_del);
	return (-1);
}

void	ft_replace_cnt(t_list *old, t_list **donor, void *new)
{
	free(old->content);
	old->content = new;
	old->content_size += (*donor)->content_size;
	ft_lstdelone(donor, &ft_del);
}
