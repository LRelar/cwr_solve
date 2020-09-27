/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_dummy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:30:49 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/28 22:45:54 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static	void	ft_place_varitype(t_format *formstat, \
											t_varitype *cont)
{
	t_varitype			*ptr;

	if (!(formstat->first))
	{
		formstat->first = cont;
		return ;
	}
	if (cont->vari_num < formstat->first->vari_num)
	{
		cont->next = formstat->first;
		formstat->first = cont;
		return ;
	}
	ptr = formstat->first;
	while (ptr->next && (ptr->next->vari_num < cont->vari_num))
		ptr = ptr->next;
	cont->next = ptr->next;
	ptr->next = cont;
}

uint8_t					ft_place_dummy(t_format *formstat, \
													t_fword *format)
{
	if (formstat->errflag)
		return (1);
	if (format->vari_cont)
		ft_place_varitype(formstat, format->vari_cont);
	return (0);
}
