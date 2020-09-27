/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:20:41 by kokeefe           #+#    #+#             */
/*   Updated: 2019/11/22 06:25:05 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_wipe_structs(t_format *formstat, t_fword *format, \
														const char *callername)
{
	t_varitype			*ptr;
	t_varitype			*next;

	(void)callername;
	if (formstat && (ptr = formstat->first))
	{
		formstat->first = NULL;
		while (ptr)
		{
			next = ptr->next;
			free(ptr);
			ptr = next;
		}
	}
	if (!format)
		return (1);
	if (format->var_sub->reg_save_area)
	{
		va_end(format->var_sub);
		ft_bzero((void *)&(format->var_sub), sizeof(va_list));
	}
	if (format->vari_cont)
		ft_memdel((void **)&(format->vari_cont));
	return (1);
}
